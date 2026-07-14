Tags: #stl #cp4 #estrutura #primitiva #bst #set #multiset
Pré-requisitos: C++ Básico
MOC: [[MOC - ED]]

## 💡 O que é? (O Insight)
Árvores de Busca Binária balanceadas (implementadas na STL como **Red-Black Trees**). Mantêm os elementos sempre ordenados e permitem buscas logarítmicas. O `set` armazena exclusivamente chaves únicas; o `multiset` permite valores duplicados.
*Aviso de Maratona:* O overhead de memória e constante oculta de tempo é alto devido às alocações dinâmicas de nós individuais e saltos de ponteiros em memória fragmentada.

## ⏱️ Complexidade dos Métodos
| Método | Complexidade | Uso em Maratona |
|---|---|---|
| `.insert(val)` / `.emplace(val)` | $O(\log N)$ | Insere preservando a ordenação da árvore |
| `.erase(val)` | $O(\log N)$ + contagem | Remove o valor (ou **todas** as cópias no multiset) |
| `.erase(it)` | $O(1)$ amortizado | Remove exatamente o nó apontado pelo iterador |
| `.find(val)` / `.count(val)` | $O(\log N)$ | Busca binária rápida |
| `.lower_bound(val)` | $O(\log N)$ | Retorna iterador para o **primeiro elemento $\ge$ val** |
| `.upper_bound(val)` | $O(\log N)$ | Retorna iterador para o **primeiro elemento $>$ val** |

## ⚠️ Gotchas & Edge Cases (Onde quebra)

- **O Bug do Destruidor no `multiset::erase(val)` (WA/RTE fatal):** Em um `multiset` contendo `{5, 5, 5}`, chamar `ms.erase(5)` remove **todas as 3 cópias de uma vez**, destruindo sua lógica de contagem em janelas deslizantes ou linhas de varredura.

  - *Correção em O(1) amortizado:* Passe o iterador retornado pelo `.find()`:
  
    ```cpp
    auto it = ms.find(5);
    if (it != ms.end()) ms.erase(it); // Apaga estritamente UMA instância
    ```

- **TLE por Função Genérica de Busca (O Erro de $O(N)$):** Escrever `auto it = std::lower_bound(s.begin(), s.end(), val);`. Como os iteradores de árvores não são de acesso aleatório (*Random Access Iterators*), a função global da STL é obrigada a avançar ponteiro por ponteiro, rodando em **$O(N)$**.
  - *Correção:* Chame exclusivamente o método membro, que desce a árvore em **$O(\log N)$**: `auto it = s.lower_bound(val);`.

- **Erro de Compilação por Imutabilidade:** Você **não pode** modificar o valor de um elemento apontado pelo iterador de um set (`*it = x;`), pois os iteradores são implicitamente `const`. Tentar fazer isso quebraria a ordenação estrutural da árvore. Para alterar, você deve remover o antigo (`.erase(it)`) e inserir o novo (`.insert(x)`).

- **A Armadilha do `.count()` em `multiset`:** Se um `multiset` tiver $K$ cópias de um elemento, chamar `ms.count(val)` roda em tempo **$O(\log N + K)$**. Se $K$ for próximo de $N$, isso degrada para uma busca linear! Se quiser apenas testar existência, use `.find(val) != ms.end()`.

## 💻 Snippet de Ouro: Lower/Upper Bound Seguro
Busca rápida para encontrar elementos que sejam maiores, menores ou limites exatos sem cair em Segmentation Fault por desreferenciar `.end()`.

```cpp
#include <bits/stdc++.h>
using namespace std;

void exemplo_bound() {
    set<int> s = {10, 20, 30, 40, 50};

    // 1. Achar o menor elemento QUE SEJA >= X (ex: X = 25 -> retorna 30)
    auto it1 = s.lower_bound(25);
    if (it1 != s.end()) {
        cout << ">= 25: " << *it1 << "\n";
    }

    // 2. Achar o maior elemento QUE SEJA <= X (ex: X = 25 -> retorna 20)
    // Truque de maratona: Use o upper_bound para achar o primeiro > X,
    // e depois volte 1 casa com o iterador!
    auto it2 = s.upper_bound(25);
    if (it2 != s.begin()) {
        --it2; // Seguro e roda em O(1) amortizado
        cout << "<= 25: " << *it2 << "\n";
    }

    // 3. Apagar elemento de forma segura em multiset mantendo o resto:
    multiset<int> ms = {5, 5, 5};
    auto it3 = ms.find(5);
    if (it3 != ms.end()) ms.erase(it3); 
    // ms agora tem {5, 5}
}
```

## Problemas Práticos & Ligações

- [[Line Sweep]] (Algoritmos de Linha de Varredura para geometria plana, interseção de retas ou união de retângulos).

- [[Dijkstra]] (Implementação alternativa usando `set<pair<int, int>>` no lugar da priority_queue quando o problema exige `.erase()` de vértices com distâncias antigas via _Decrease-Key_).

- [[Convex Hull Trick]] (Versão dinâmica usando `multiset` com custom comparator onde a ordem das retas é mantida em tempo real).

- Manutenção dinâmica de máximo/mínimo/mediana com remoções no meio do processo (quando a `priority_queue` falha por não ter `.erase()`).