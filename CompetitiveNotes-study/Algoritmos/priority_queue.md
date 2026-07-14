Tags: #stl #cp4 #estrutura #primitiva #heap #priority_queue
Pré-requisitos: C++ Básico
MOC: [[MOC - ED]]

## 💡 O que é? (O Insight)
Fila de prioridade implementada como um **Heap Binário**. Garante que o elemento de maior prioridade (segundo um critério de ordenação) esteja sempre acessível no topo em tempo constante real, enquanto inserções e remoções custam tempo logarítmico para manter o balanceamento da árvore implícita.

## ⏱️ Complexidade dos Métodos
| Método | Complexidade | Uso em Maratona |
|---|---|---|
| `.push(val)` / `.emplace(args)` | $O(\log N)$ | Insere o elemento e rebalanceia o Heap |
| `.pop()` | $O(\log N)$ | Remove o elemento do topo e rebalanceia o Heap |
| `.top()` | $O(1)$ | Retorna uma referência constante ao topo |
| `.size()` / `.empty()` | $O(1)$ | Verificação de estado |

## ⚠️ Gotchas & Edge Cases (Onde quebra)

- **A Armadilha do Max-Heap Padrão (WA silencioso em Grafos):** Por padrão, a STL implementa a `priority_queue` como um **Max-Heap** (ordem decrescente, o maior valor fica no topo). Se você implementar um Dijkstra e esquecer de converter para **Min-Heap**, o algoritmo processará os caminhos *mais longos* primeiro, gerando Wrong Answer sem dar nenhum erro na compilação.

- **Falta da operação `Decrease-Key` / `Update`:** O C++ não possui um método nativo para atualizar o valor de um nó que já está dentro do Heap (ex: quando encontramos um caminho menor para um vértice no Dijkstra).
  - *Correção de Maratona (Lazy Deletion):* Simplesmente insira uma **nova cópia** `{novo_custo, vertice}` com o valor atualizado via `.push()`. Quando o topo antigo for desempilhado futuramente, ignore-o checando a distância válida: `if (d > dist[u]) continue;`.

- **Invalidação de Referência no `.pop()`:** Como os elementos são reorganizados internamente no array contíguo do Heap, capturar uma referência por nome (`const auto& x = pq.top();`) e em seguida chamar `pq.pop()` **invalida a referência `x` antes mesmo de você usá-la**, causando comportamentos bizarros ou RTE. Copie o valor por valor (`auto x = pq.top();`) antes do pop.

## 💻 Snippet de Ouro: Min-Heap e Custom Comparators
Diferente da `queue` e da `stack`, aqui o snippet é obrigatório porque a sintaxe verbosa do C++ para alterar a ordem da fila de prioridade é um ponto clássico de perda de tempo em competições.

```cpp
#include <bits/stdc++.h>
using namespace std;

// 1. Sintaxe Padrão para Min-Heap (Menor valor no topo)
// Essencial para Dijkstra e Prim:
using pii = pair<long long, int>; // {distancia, vertice}
priority_queue<pii, vector<pii>, greater<pii>> min_heap;

// 2. Truque de Maratona para Min-Heap SEM usar greater<pii>:
// Se não quiser digitar a sintaxe longa, use o Max-Heap padrão,
// mas insira os custos NEGATIVADOS:
priority_queue<pii> pq_truque;
// pq_truque.push({-custo, vertice});
// long long custo_real = -pq_truque.top().first;

// 3. Sintaxe com Custom Comparator (Para structs e lógicas complexas):
struct Tarefa {
    int id, prioridade;
};

// CUIDADO: Para a prioridade máxima ficar no topo, o operador
// deve retornar true quando 'a' tiver MENOR prioridade que 'b' (logica invertida do sort)!
struct Comp {
    bool operator()(const Tarefa& a, const Tarefa& b) {
        if (a.prioridade == b.prioridade) return a.id > b.id; // Desempate por ID menor
        return a.prioridade < b.prioridade; // Maior prioridade no topo
    }
};

priority_queue<Tarefa, vector<Tarefa>, Comp> pq_custom;
```

## Problemas Práticos & Ligações

- [[Dijkstra]] (Algoritmo de caminho mínimo em grafos com pesos não-negativos em $O((V + E) \log V)$).
- [[Algoritmo de Prim]] (Encontrar Árvore Geradora Mínima - MST).
- [[Algoritmos Ambrosos (Greedy)]] (Problemas de agendamento de tarefas e manutenção contínua dos $K$ maiores/menores elementos em uma stream de dados em $O(N \log K)$).
- [[Huffman Coding]] e fusão de arquivos com custo mínimo.