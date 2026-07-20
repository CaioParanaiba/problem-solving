---
aliases: [std::queue, FIFO Queue, Fila]
tags: #stl #cp4 #estrutura #primitiva #queue
data_criacao: 2024-01-15
status: consolidado
---

# 📚 queue

**MOC:** [[MOC - Estruturas de Dados]]
**Pré-requisitos:** C++ Básico

---

## 💡 O que é? (O Insight)
Fila FIFO (*First-In, First-Out*). É um *container adapter* da STL (geralmente encapsulando um `deque`) que restringe o acesso estritamente à primeira e à última posição da estrutura.

---

## ⏱️ Complexidade dos Métodos

| Método | Complexidade | Uso em Maratona |
|---|---|---|
| `.push(val)` | $O(1)$ | Enfileira um elemento no final da fila |
| `.pop()` | $O(1)$ | Remove o elemento da frente (não retorna o valor!) |
| `.front()` | $O(1)$ | Retorna uma referência ao primeiro elemento |
| `.back()` | $O(1)$ | Retorna uma referência ao último elemento inserido |
| `.size()` / `.empty()` | $O(1)$ | Verificação de estado |

---

## ⚠️ Pegadinhas Clássicas e Edge Cases

- [ ] **A Armadilha da Ausência de `.clear()`:** Tentar chamar `q.clear()` para zerar a fila entre múltiplos casos de teste causa **Erro de Compilação (CE)**, pois a estrutura não implementa esse método.
  - *Correção em $O(1)$:* Reatribua a variável com uma fila vazia: `q = queue<int>();` ou use `while(!q.empty()) q.pop();` (a reatribuição tem performance superior no juiz).

- [ ] **RTE por Acesso em Fila Vazia:** Chamar `.front()`, `.back()` ou `.pop()` em uma fila onde `q.empty() == true` gera **Runtime Error (Segmentation Fault)** instantâneo. Sempre proteja com `if (!q.empty())` ou dentro de laços de processamento.

- [ ] **Overhead de Alocação vs. Array Estático:** O `std::queue` é construído sobre um `std::deque` por padrão. Em problemas de limite de tempo extremamente rigoroso, a alocação dinâmica em blocos fragmentados pode ser mais lenta que uma fila estática em array contíguo (`int q[MAXN], head=0, tail=0`). Para 99% da OBI/ICPC, a STL é suficiente, mas em problemas com $10^7$ operações, prefira o array estático ou dê um `.reserve()` usando um `std::vector` como base se não precisar de `.pop()` limpo de memória.

---

## 🎯 Problemas Práticos

| Problema | Juiz | Dificuldade | Status | Notas / Pegadinhas |
| :--- | :--- | :---: | :---: | :--- |
| [[BFS]] | - | - | - | Busca em Largura e exploração em camadas/grid 2D |
| [[Algoritmo de Kahn]] | - | - | - | Ordenação Topológica em grafos direcionados acíclicos |
| [[Multi-source BFS]] | - | - | - | Injeção simultânea de múltiplos nós na fila inicial |

---

## 🔄 Histórico de Revisão & Erros Comuns
* *Anotações pessoais de erros em simulados.*