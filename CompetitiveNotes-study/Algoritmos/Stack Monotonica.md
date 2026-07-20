---
aliases:
  - Stack Monotônica
  - Monotonic Stack
  - Largest Rectangle in Histogram
status: consolidado
---

# 📚 Stack Monotônica - Maior Retângulo em Histograma

**MOC:** [[MOC - Estruturas de Dados]] | [[Técnicas de Otimização]]
**Pré-requisitos:** [[Stack]]
**Criador:** 

---

## 💡 O que é? (O Insight)
A **Stack Monotônica** é uma variação da estrutura de pilha tradicional onde os elementos são mantidos em uma ordem estritamente crescente (ou decrescente). 

O grande insight para o problema do **Maior Retângulo em um Histograma** (e problemas similares de *Next Greater/Smaller Element*) é:
* Quando encontramos uma barra menor do que a barra no topo da pilha, sabemos que a barra do topo **não pode mais ser estendida para a direita**.
* Isso define o **limite direito** exclusivo daquela barra. O **limite esquerdo** é o elemento que ficou logo abaixo dela na pilha após o `pop()` (pois os elementos na pilha estão em ordem crescente).
* Com ambos os limites definidos, podemos calcular a área máxima possível utilizando aquela barra como a menor altura do retângulo em $\mathcal{O}(1)$.

---

## ⚙️ Como funciona? (Passo a Passo)

1. **Manutenção da Ordem:** Iteramos pelo array de alturas da esquerda para a direita. Mantemos na pilha apenas os **índices** das barras em ordem crescente de altura.
2. **Violação da Monotonicidade:** Se a barra atual `v[i]` for menor que a barra no topo da pilha `v[st.top()]`:
   * Desempilhamos o índice do topo: `h = v[st.top()]` (esta será a altura do retângulo que estamos testando).
   * Calculamos a largura `l` que essa altura `h` consegue se estender:
     * Se a pilha ficar **vazia**, significa que a barra `h` era menor ou igual a todas as barras à esquerda até o início do array. Logo, `l = i`.
     * Caso contrário, ela se estende desde o elemento atual à direita (`i`) até o elemento que restou no topo da pilha à esquerda (`st.top()`). Logo, `l = i - st.top() - 1`.
   * Atualizamos a resposta: `ans = max(ans, l * h)`.
3. **O Truque do Sentinela (`v[n] = 0`):** Ao adicionar uma barra de altura `0` no final do vetor (`i = n`), garantimos que todas as barras restantes na pilha serão forçadas a sair ao término do loop, eliminando a necessidade de um loop `while (!st.empty())` extra no final!

---

## ⏱️ Complexidade

| Medida | Complexidade | Explicação |
| :--- | :---: | :--- |
| **Tempo** | **$\mathcal{O}(N)$** | Embora haja um loop `while` dentro do `for`, cada índice de $0$ a $N$ é empilhado **exatamente uma vez** e desempilhado **no máximo uma vez**. A complexidade amortizada por elemento é $\mathcal{O}(1)$. |
| **Espaço** | **$\mathcal{O}(N)$** | No pior caso (um histograma estritamente crescente), a pilha armazenará até $N+1$ índices, além do vetor de alturas de tamanho $N+1$. |

---

## 💻 Código Base (Otimizado para Maratona)

```cpp
#include <bits/stdc++.h>
using namespace std;

long long maxHistogramArea(const vector<int>& heights) {
    int n = (int)heights.size();
    stack<int> st; // Guarda ÍNDICES das barras em ordem crescente de altura
    long long max_area = 0;

    // Iteramos de 0 até n inclusive.
    // Para i == n, usamos uma altura virtual 0 (SENTINELA INLINE) 
    // para forçar o desempilhamento de todos os elementos restantes na pilha.
    for (int i = 0; i <= n; i++) {
        long long current_h = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > current_h) {
            long long h = heights[st.top()];
            st.pop();
            
            // Se a pilha esvaziar, o limite esquerdo é o início do array (largura = i).
            // Caso contrário, vai do elemento atual à direita até o novo topo da pilha à esquerda.
            long long w = st.empty() ? i : (i - st.top() - 1);
            
            max_area = max(max_area, h * w);
        }
        st.push(i);
    }

    return max_area;
}
```

---

## ⚠️ Pegadinhas Clássicas e Edge Cases (Onde não errar)

1. **Overflow de Inteiros (TLE / WA clássico):**
   * A altura pode ser até $10^9$ e a largura até $10^5$. O produto `l * h` pode chegar a $10^{14}$, estourando o limite de um inteiro de 32 bits signed ($ pprox 2 	imes 10^9$). O uso de `#define int long long` é indispensável!
2. **Esquecer de esvaziar a pilha no final:**
   * Se você não usar o truque do **sentinela** (`v[n] = 0` e loop até `i <= n`), elementos crescentes ficarão presos na pilha ao final do array. Se esquecer do loop final para desempilhá-los, tomará **WA**.
3. **Limite de Memória (Memory Limit Exceeded - MLE):**
   * Em juízes muito antigos (como SPOJ ou POJ com limite de 16MB/32MB), usar `#define int long long` dobra o consumo de RAM em vetores grandes. Se tomar MLE, mude o vetor de alturas e índices da pilha para `int32_t` e faça cast `(long long)l * h` apenas na hora de calcular a área.
4. **Barras de alturas iguais:**
   * Usar `>` ou `>=` na condição do `while` não altera a resposta final máxima, pois o último elemento de um bloco de alturas iguais será processado e garantirá a expansão correta para a esquerda.
5. **Overhead de Alocação em Múltiplos Casos de Teste:**
   * Em problemas com muitos milhares de casos de teste pequenos (`T > 10^5`), alocar `vector<int> v(n + 1, 0)` repetidamente dentro do `while` pode gerar TLE por overhead de alocação dinâmica. Nesses casos, prefira declarar `vector<int> v;` globalmente ou no início da função e usar `v.resize(n + 1)` ou reaproveitar memória.

---

## 🎯 Problemas Práticos

| Problema                                                                                            | Juiz     | Dificuldade |    Status    | Notas / Pegadinhas                                                     |
| :-------------------------------------------------------------------------------------------------- | :------- | :---------: | :----------: | :--------------------------------------------------------------------- |
| **[HISTOGRA - Largest Rectangle in a Histogram](https://www.spoj.com/problems/HISTOGRA/)**          | SPOJ     |    Média    |   🟩 Feito   | Problema clássico base para este template.                             |
| **[Advertisement](https://cses.fi/problemset/task/1142)**                                           | CSES     |    Média    | 🔲 Pra fazer | Implementação direta, mas atenção aos limites de $N \le 2 \cdot 10^5$. |
| **[Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)** | LeetCode |   Difícil   | 🔲 Pra fazer | Testar o tempo de execução e alocação.                                 |
| **[Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)**                           | LeetCode |   Difícil   | 🔲 Pra fazer | Aplicação 2D: roda o histograma para cada linha da matriz.             |
