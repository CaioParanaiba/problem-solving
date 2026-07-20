---
aliases: [2D Prefix Sum, Matriz de Soma Acumulada, Soma de Submatriz em O(1), Prefixo 2D]
tags: #cp #algoritmo #obi #icpc #estruturas_de_dados #matematica #pd
data_criacao: <% tp.file.creation_date("YYYY-MM-DD") %>
status: consolidado
---

# 📚 Prefixo 2D (2D Prefix Sum)

**MOC:** [[MOC - Estruturas de Dados]] | [[Prefixo 1D]]
**Pré-requisitos:** [[Princípio da Inclusão-Exclusão]]
**Autor:**

---

## 💡 O que é? (O Insight)

> [!SUMMARY] Resumo Rápido
> É uma generalização do vetor de soma prefixada para duas dimensões. Permite calcular a soma total de qualquer submatriz retangular em tempo constante $\mathcal{O}(1)$ após um pré-processamento linear em relação à área total da matriz.

* **O Problema:** Calcular a soma dos elementos de uma submatriz $(r_1, c_1)$ até $(r_2, c_2)$ por força bruta exige percorrer toda a área retangular, custando até $\mathcal{O}(N \times M)$ por consulta. Para $Q$ consultas, o tempo total seria $\mathcal{O}(Q \times N \times M)$, resultando em inevitável **TLE** (Time Limit Exceeded) na maratona.

* **O Insight Clave:** Utilizamos o **Princípio da Inclusão-Exclusão** no plano de coordenadas da grade. A célula $\text{pref}[i][j]$ armazena a soma de todo o retângulo que vai da origem $(1,1)$ até a célula $(i,j)$. Para extrair a área de um sub-retângulo interno qualquer, pegamos a soma acumulada do retângulo maior, subtraímos os retângulos acima e à esquerda que não fazem parte da consulta, e somamos de volta a intersecção deles (canto superior-esquerdo) que acabou sendo subtraída duas vezes.

---

## ⚙️ Como funciona? (Passo a Passo)

1. **Estado Inicial (Indexação 1-Based):** Criamos a matriz de prefixo $\text{pref}$ com dimensões $(N+1) \times (M+1)$ preenchida com zeros. **A indexação 1-based é obrigatória para a clareza deste algoritmo**: a linha $0$ e a coluna $0$ atuam como sentinelas neutros ($0$), eliminando a necessidade de checar bordas com `if (i > 0)` no meio dos laços.

![[Pasted image 20260715132750.png|275]]

2. **Construção / Pré-processamento:** Percorremos a matriz da linha $1$ a $N$ e coluna $1$ a $M$. A transição de estado para preencher cada célula é:
   $$\text{pref}[i][j] = \text{mat}[i][j] + \text{pref}[i-1][j] + \text{pref}[i][j-1] - \text{pref}[i-1][j-1]$$
3. **Consulta em $\mathcal{O}(1)$:** Para responder à soma do retângulo compreendido entre o canto superior-esquerdo $(r_1, c_1)$ e o canto inferior-direito $(r_2, c_2)$ (com limites inclusivos), aplicamos o isolamento de área:
   $$\text{Soma} = \text{pref}[r_2][c_2] - \text{pref}[r_2][c_1 - 1] - \text{pref}[r_1 - 1][c_2] + \text{pref}[r_1 - 1][c_1 - 1]$$

---

## ⏱️ Análise de Complexidade

| Medida | Complexidade | Explicação / Justificativa |
| :--- | :---: | :--- |
| **Tempo (Pré-processamento)** | **$\mathcal{O}(N \times M)$** | Duplo laço varrendo todas as células da grade exatamente uma vez, realizando apenas adições e subtrações em tempo constante. |
| **Tempo (Por Query)** | **$\mathcal{O}(1)$** | Apenas quatro acessos posicionais na matriz de prefixo e três operações aritméticas elementares por consulta. |
| **Espaço (Memória Auxiliar)** | **$\mathcal{O}(N \times M)$** | Consumo para armazenar a tabela de somas acumuladas. Em problemas de memória extremamente restrita, pode ser $\mathcal{O}(1)$ extra se permitida a sobrescrita direta na matriz de leitura. |

---

## 💻 Código Base (Essência: Construção & Consulta)

> [!TIP] Dica de Contest
> Mantenha a essência limpa e isolada da lógica de I/O. As duas funções abaixo ilustram a montagem e a consulta canônicas para maratona de programação.

```cpp
#include <bits/stdc++.h>
using namespace std;

// === [ ESSÊNCIA: PREFIXO 2D ] ===
// Constroi a matriz de prefixos em O(N * M) e responde a consultas em O(1).
// Assume que 'mat' já está em indexação 1-based (tamanho [N+1][M+1]).

void build_2d_prefix(const vector<vector<long long>>& mat, vector<vector<long long>>& pref, int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = mat[i][j] 
                       + pref[i - 1][j] 
                       + pref[i][j - 1] 
                       - pref[i - 1][j - 1];
        }
    }
}

// Retorna a soma da submatriz retangular do canto (r1, c1) até (r2, c2) [Limites Inclusivos]
long long query_2d_prefix(const vector<vector<long long>>& pref, int r1, int c1, int r2, int c2) {
    return pref[r2][c2] 
         - pref[r2][c1 - 1] 
         - pref[r1 - 1][c2] 
         + pref[r1 - 1][c1 - 1];
}
```

---

## ⚠️ Pegadinhas Clássicas e Edge Cases (Checklist de Contest)

- [ ] **Overflow (32 vs 64 bits):** Uma matriz $2000 \times 2000$ com inteiros na ordem de $10^9$ soma até $4 \times 10^{15}$. Se usar `int` comum (32 bits), ocorrerá overflow silencioso durante o build. **Sempre use `long long` para a matriz de acumulação `pref`**.

- [ ] **Estouro de Memória (MLE):** Matrizes de `long long` consomem 8 bytes por célula. Uma matriz $5000 \times 5000$ consome cerca de **200 MB** de RAM. Se o limite do problema for restrito (ex: $\le 64\text{ MB}$), verifique se o valor máximo cabe em um `int` ou achate a matriz em um array linear 1D para evitar overhead de ponteiros do `vector<vector<T>>`.

- [ ] **Índices Invertidos / Desordenados:** Em muitos problemas, os vértices da consulta podem vir sem ordem garantida ($r_1 > r_2$ ou $c_1 > c_2$). Garanta a ordenação aplicando `if (r1 > r2) swap(r1, r2);` e `if (c1 > c2) swap(c1, c2);` antes de chamar a query.

- [ ] **Confusão Cartesiana vs Matricial:** Evite misturar $(X, Y)$ cartesiano com `[linha][coluna]`. Mantenha a convenção estrita de que o primeiro parâmetro é sempre a linha ($r$ ou $y$) e o segundo a coluna ($c$ ou $x$).

- [ ] **Conversão 0-Based do Input:** Se as queries do problema vierem indexadas em 0 (ex: $0 \le r < N$), lembre-se de somar $+1$ em todas as coordenadas na hora de realizar a consulta.

---

## 🔄 Histórico de Revisão & Erros Comuns
* *Use este espaço no Obsidian para anotar erros práticos de simulados e contestações passadas relacionados a este tópico.*