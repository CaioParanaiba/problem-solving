Tags: #stl #cp4 #estrutura #primitiva #deque
Pré-requisitos: C++ Básico
MOC: [[MOC - ED]]

## 💡 O que é? (O Insight)
Fila de ponta dupla (*Double-Ended Queue*). Permite inserção e remoção em ambas as extremidades em tempo constante real $O(1)$.
Diferente do `vector`, o `deque` **não é contíguo em memória**: ele é alocado internamente como uma "página de páginas" (blocos de memória fixos interligados por ponteiros). Isso significa que ele cresce sem precisar realocar e copiar todos os elementos existentes, mas perde a otimização máxima de cache da CPU.

## ⏱️ Complexidade dos Métodos
| Método | Complexidade | Uso em Maratona |
|---|---|---|
| `.push_front(val)` / `.pop_front()` | $O(1)$ | Inserção e remoção instantânea no início |
| `.push_back(val)` / `.pop_back()` | $O(1)$ | Inserção e remoção instantânea no final |
| `dq[i]` | $O(1)$ | Acesso aleatório por índice (constante mais lenta que o `vector`) |
| `.front()` / `.back()` | $O(1)$ | Retorna referência ao primeiro/último elemento sem remover |
| `.size()` / `.empty()` | $O(1)$ | Verificação de estado |
| `.clear()` | $O(N)$ | Destrói todos os elementos da estrutura |

## ⚠️ Gotchas & Edge Cases (Onde quebra)
- **A Armadilha de Performance (Overhead de Cache):** Substituir vetores ou filas comuns por `deque` "por comodidade" é um erro tático. Devido aos saltos de ponteiros entre os blocos de memória, o acesso sequencial no `deque` tem uma constante oculta até 3x a 5x mais lenta que o `vector`. Use **apenas** quando a operação de `.pop_front()` ou `.push_front()` for estritamente necessária.
- **Invalidação de Iteradores no Meio do Laço:** Fazer qualquer operação de push/pop nas extremidades **invalida todos os iteradores** existentes da estrutura (embora referências diretas a elementos como `&dq[0]` permaneçam válidas na memória). Nunca guarde iteradores do `deque` enquanto altera seu tamanho.
- **RTE nas Extremidades:** Exatamente como no `queue` e na `stack`, chamar `.front()`, `.back()`, `.pop_front()` ou `.pop_back()` com `dq.empty() == true` causa **Runtime Error (Segmentation Fault)** instantâneo. Sempre proteja com `if (!dq.empty())`.

## 💻 Snippet de Ouro: Truque de Sintaxe e Reserva de Espaço
Como o `deque` é fragmentado em blocos, **ele não possui o método `.reserve(N)`** da STL como o `vector`. Se você precisar de uma fila de ponta dupla de tamanho pré-alocado fixo (para preencher via índices), declare com o tamanho no construtor.

```cpp
// Inicializa o deque já com N posições preenchidas com 0 em O(N)
deque<int> dq(N, 0); 

// Iteração segura e ultra rápida com C++17 (Structured Binding em deques de pares):
deque<pair<int, int>> dq_pairs;
for (const auto& [custo, vertice] : dq_pairs) {
    // Processamento sem cópias (evita TLE de cópia por valor)
}
```

## Problemas Práticos & Ligações

- [[BFS 0-1]] (Encontrar caminho mínimo em grafos com pesos estritamente $0$ ou $1$ em tempo linear $O(V + E)$ sem overhead do logaritmo do Dijkstra).
- [[Sliding Window]] (Manutenção do valor máximo/mínimo em uma janela deslizante em tempo linear $O(N)$ usando um Monotone Deque).
- [[Convex Hull Trick]] (Otimização de Programação Dinâmica onde retas são inseridas em ordem monotônica).