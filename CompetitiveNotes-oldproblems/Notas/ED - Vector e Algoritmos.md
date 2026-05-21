# Vector e Algoritmos
É um array dinâmico, vetor de tamanho indefinido.
`vector<tipo> nome_do_vetor;`

## Comandos do Vector
* `v.push_back(valor)` $\rightarrow$ Adiciona elemento no final.
* `v.pop_back()` $\rightarrow$ Remove o último elemento.
* `v.size()` $\rightarrow$ Retorna o tamanho.
* `v[indice]` $\rightarrow$ Acessa elementos (assim como `.front()` e `.back()`).
* `v.begin()` e `v.end()` $\rightarrow$ Retornam iteradores para o início e logo após o último elemento.
* `v.clear()` $\rightarrow$ Limpa o vetor (Tamanho 0).
* `v.empty()` $\rightarrow$ `true` = Vazio / `false` = Não vazio.
* `v.resize(novo_tamanho)` $\rightarrow$ Muda o tamanho do vetor.

---
## Algoritmos (Muito úteis em CP)
*Necessário usar os iteradores `.begin()` e `.end()`*

* **`sort(begin, end, metodo)`** $\rightarrow$ $O(N \log N)$
  * O método padrão é `a < b` (Crescente).
  * Exemplo com Lambda customizada: 
    ```cpp
    sort(v.begin(), v.end(), [](auto a, auto b){ return a > b; });
    ```
* **`binary_search(begin, end, valor)`** $\rightarrow$ $O(\log N)$
  * Retorna `bool` (`true` se achou, `false` se não).
* **`lower_bound(begin, end, valor)`** $\rightarrow$ $O(\log N)$
  * Retorna um *iterador* para o primeiro elemento $\ge$ valor.
* **`upper_bound(begin, end, valor)`** $\rightarrow$ $O(\log N)$
  * Retorna um *iterador* para o primeiro elemento $>$ valor.
* **`reverse(begin, end)`** $\rightarrow$ $O(N)$
* **`count(begin, end, valor)`** $\rightarrow$ $O(N)$