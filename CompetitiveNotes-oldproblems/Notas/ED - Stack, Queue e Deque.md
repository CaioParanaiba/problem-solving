# Stack, Queue e Deque
*Bibliotecas necessárias: `<stack>`, `<queue>`, `<deque>` ou `<bits/stdc++.h>`*

> [!warning] AVISO CRÍTICO
> Nenhuma dessas três estruturas clássicas possui iteradores. Ou seja, **NÃO DÁ** para usar `sort()`, `lower_bound()` ou iterar com `for(auto x : s)`.

## 1. Stack (Pilha)
Estrutura **LIFO** (Last In, First Out) - O último a entrar é o primeiro a sair.
`stack<tipo> S;`

* **Comandos Principais ($O(1)$):**
  * `S.push(valor)` $\rightarrow$ Coloca variável ou valor no Topo.
  * `S.pop()` $\rightarrow$ Remove o Topo.
  * `S.top()` $\rightarrow$ Acessa o valor do Topo (não remove).
  * `S.size()` $\rightarrow$ Tamanho da stack.
  * `S.empty()` $\rightarrow$ Verifica se é vazia (Retorna True/False).

## 2. Queue (Fila)
Estrutura **FIFO** (First In, First Out) - O primeiro a entrar é o primeiro a sair.
`queue<tipo> Q;`

* **Comandos Principais ($O(1)$):**
  * `Q.push(valor)` $\rightarrow$ Coloca no final (Back).
  * `Q.pop()` $\rightarrow$ Remove do começo (Front).
  * `Q.front()` $\rightarrow$ Acessa o valor do começo.
  * `Q.back()` $\rightarrow$ Acessa o valor do final.
  * `Q.size()` $\rightarrow$ Tamanho da fila.
  * `Q.empty()` $\rightarrow$ Verifica se é vazia.

## 3. Deque (Fila Flexível)
Entra e sai por ambas as pontas.
`deque<tipo> D;`

* **Comandos Principais ($O(1)$):**
  * `D.push_front(valor)` / `D.pop_front()`
  * `D.push_back(valor)` / `D.pop_back()`
  * `D.front()` / `D.back()`
* **Comandos Extras (Mais lentos):**
  * `D.insert(iterador, valor)` $\rightarrow$ Meio $O(N)$
  * `D.erase(iterador)` $\rightarrow$ Meio $O(N)$