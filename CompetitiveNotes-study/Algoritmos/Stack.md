Tags: #stl #cp4 #estrutura #primitiva #stack
Pré-requisitos: C++ Básico
MOC: [[MOC - ED]]

## 💡 O que é? (O Insight)
Pilha LIFO (*Last-In, First-Out* - Último a entrar, primeiro a sair). É um *container adapter* da STL que restringe as operações de leitura e escrita exclusivamente ao topo da estrutura. Internamente, é construída por padrão sobre um `std::deque` (mas pode encapsular um `std::vector`). É a ferramenta nativa para processamento de estruturas aninhadas, retrocesso (*backtracking*) e conversão de recursão em laços iterativos.

## ⏱️ Complexidade dos Métodos
| Método | Complexidade | Uso em Maratona |
|---|---|---|
| `.push(val)` / `.emplace(args)`| $O(1)$ | Empilha um elemento no topo da pilha |
| `.pop()` | $O(1)$ | Remove o elemento do topo sem retornar o valor |
| `.top()` | $O(1)$ | Retorna uma referência constante ou mutável ao topo |
| `.size()` / `.empty()` | $O(1)$ | Verificação instantânea de estado |

## ⚠️ Gotchas & Edge Cases (Onde quebra)
- **A Armadilha do Ausente `.clear()`:** Exatamente como no `queue`, a classe `std::stack` não possui método `.clear()`. Tentar usá-lo entre casos de teste resultará em **Erro de Compilação (CE)**.
  - *Correção em $O(1)$:* Reatribua a variável: `st = stack<int>();` ou utilize `.emplace()` se o tipo for complexo.
- **RTE por `.top()` ou `.pop()` em Pilha Vazia:** O acesso a uma pilha vazia é um dos maiores causadores de **Runtime Error (Segmentation Fault)** na OBI. O método `.top()` tenta acessar ponteiros inválidos se `st.empty() == true`. Sempre condicione a leitura: `while (!st.empty() && st.top() ... )`.
- **A Ordem das Operações Lógicas (Short-Circuit Evaluation):** Ao checar condições na pilha (comum em janelas e parsing), certifique-se de checar `!st.empty()` **antes** de chamar `.top()`.
  - *Correto:* `while (!st.empty() && st.top() > x)` (Se vazia, o C++ não avalia o `.top()`).
  - *Fatal (RTE):* `while (st.top() > x && !st.empty())`.
- **Estouro da Pilha de Execução (Stack Overflow do Sistema) vs. `std::stack`:** Em problemas de árvores profundas ($10^5$ vértices em linha reta) ou grafos imensos, o uso de recursão nativa do C++ (`void dfs(...)`) pode causar RTE por estourar o limite da pilha de execução do SO (geralmente 8MB). Substituir a recursão por um laço `while` usando uma `std::stack<int>` joga a memória para a **Heap (RAM geral)**, evitando o crash fatal no juiz online.

## 💻 Snippet de Ouro: Mudança do Container Subjacente para Performance Máxima
Como a `std::stack` usa um `deque` por padrão, em problemas que exigem extrema performance de memória cache (onde cada milissegundo conta para evitar TLE), você pode forçar a pilha a usar um `std::vector` como base. Isso garante que os elementos fiquem contíguos na memória de forma rigorosa.

```cpp
#include <bits/stdc++.h>
using namespace std;

// Pilha otimizada para cache utilizando vetor contíguo como container base:
stack<int, vector<int>> st_rapida;

// Para limpezas ultra rápidas em problemas multicaso sem realocar memória,
// a melhor técnica de maratona é usar um vector diretamente como pilha:
vector<int> st_manual;
st_manual.reserve(100000);

// Operações equivalentes e mais rápidas no vector:
st_manual.push_back(10); // .push()
int topo = st_manual.back(); // .top()
st_manual.pop_back(); // .pop()
st_manual.clear(); // Vantagem: .clear() existe em O(1) sem liberar a capacidade!

```

## Problemas Práticos & Ligações

- [[Monotonous Stack]] (Algoritmo para achar o próximo elemento maior/menor em $O(N)$ ou cálculo de maior retângulo em histograma).
- [[DFS Iterativa]] (Busca em Profundidade em grafos e árvores sem risco de estourar a memória stack do sistema operacional).
- [[Algoritmo de Tarjan]] e [[Algoritmo de Kosaraju]] (Encontrar Componentes Fortemente Conexos - SCCs em tempo linear).
- Parsing de Expressões / Validação de Parênteses e Colchetes (Problemas clássicos de sintaxe).