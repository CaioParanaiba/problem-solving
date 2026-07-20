---
aliases: []
tags: #cp #algoritmo #obi #icpc
data_criacao: 2026-07-20
status: a_revisar
---

# 📚 Floyd-Warshall

**MOC:** [[MOC - Grafos]]
**Pré-requisitos:** [[BFS]]
**Autor:**

---

## 💡 O que é? (O Insight)
> [!SUMMARY] Resumo Rápido
> Usada para calcular o **comprimento do menor caminho** entre todos os pares de nós $i$ e $j$ de um grafo (all-pairs shortest path).

* **O Problema:** O normal seria pensar: por que não fazer [[BFS]] a partir de cada nó? Funciona (e assintoticamente é até melhor em grafos esparsos, $O(V\cdot(V+E))$ contra $O(V^3)$), mas exige resetar fila/visitados e reconstruir a lista de adjacência a cada uma das $N$ execuções, para cada caso de teste — mais estado pra gerenciar, mais chance de bug. Para grafos pequenos ($N \lesssim 500$), o ganho assintótico do BFS não compensa a complexidade extra de implementação. (Obs: BFS usa fila, não recursão — o risco de stack overflow é de DFS recursivo, não de BFS.)
* **O Insight Chave:** Armazenamos tudo em uma matriz estática; para cada trio de nós $(i, k, j)$, verificamos se passar pelo nó $k$ produz um caminho menor entre $i$ e $j$ do que o já conhecido.

---

## ⚙️ Como funciona? (Passo a Passo)

1. **Estado Inicial:** Iniciamos uma matriz de distância, onde `dis[i][i] = 0` (nó pra ele mesmo); `dis[i][j] = peso da aresta` para pares com aresta direta (em grafo não ponderado, peso = 1); e `INF` para os demais pares.
2. **Transição / Processamento:** Para cada nó $k$ liberado como intermediário, verificamos se ele encurta o caminho de $i$ até $j$:
$$
dis[i][j]=\min(dis[i][j],\,dis[i][k]+dis[k][j])
$$
   Invariante importante: depois que o loop de $k$ processa o nó $k$, `dis[i][j]` contém o menor caminho de $i$ até $j$ usando apenas nós de $\{1, ..., k\}$ como intermediários. É por isso que **$k$ tem que ser o loop mais externo** — os resultados parciais de uma passagem de $k$ viram matéria-prima para a passagem seguinte.
3. **Condição de Parada / Otimização:** Rodamos 3 for aninhados até `MAXN`, na ordem `k`, `i`, `j`.

---

## ⏱️ Análise de Complexidade

| Medida | Complexidade | Explicação / Justificativa |
| :--- | :---: | :--- |
| **Tempo (Inicialização da matriz)** | **$\mathcal{O}(N^2)$** | Preencher a matriz com pesos das arestas, 0 na diagonal e INF no resto. |
| **Tempo (Algoritmo)** | **$\mathcal{O}(N^3)$** | Triplo loop `k, i, j` — custo fixo, não depende de quantas arestas existem. |
| **Espaço (Memória Auxiliar)** | **$\mathcal{O}(N^2)$** | Matriz de distâncias `N x N`. |

---

## 💻 Código Base (Módulo / Função Limpa)

> [!TIP] Dica de Contest
> Implementação modular e flexível. Evite código engessado em `main()`; prefira funções limpas, lambdas ou structs fáceis de adaptar para diferentes formatos de entrada.

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const long long INF = 1e18;
long long dis[MAXN][MAXN];

// Pré-requisito: dis[][] já deve estar inicializada antes de chamar
// (diagonal = 0, arestas = peso, resto = INF)
void Build_FW(int n){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
```

> [!NOTE] Sobre o `long long`
> Se usar `INF = 1e18` como sentinela, `dis[i][k] + dis[k][j]` pode somar até `2e18` no pior caso — ainda cabe em `long long` (limite ~9.2e18), mas não cabe em `int`. Sempre usar `long long` quando trabalhar com INF grande.

---

## ⚠️ Pegadinhas Clássicas e Edge Cases (Checklist de Contest)

- [ ] **Overflow (32 vs 64 bits):** `dis[i][k] + dis[k][j]` pode somar dois valores de `INF` — se `INF` for grande (ex: `1e18`), é obrigatório `long long`. Se `INF` for pequeno (ex: `1e9`), `int` já resolve, mas cuidado ao migrar de problema pra problema.
- [ ] **Ordem dos loops:** `k` **sempre** por fora. Trocar a ordem quebra a invariante (resultados intermediários incompletos sendo usados antes da hora).
- [ ] **Nós que não aparecem no caso de teste:** Quando os rótulos dos nós não são contíguos (ex: só aparecem 1, 2 e 4, nunca 3), não inclua nós "fantasmas" na resposta final (soma/média). Guarde quais nós realmente apareceram (`set` ou vetor booleano) e filtre por eles.
- [ ] **Excluir a diagonal:** Ao somar/usar as distâncias finais, geralmente `dis[i][i] = 0` não deve entrar na conta (não é um "caminho" de verdade).
- [ ] **Verificar `INF` antes de usar:** Se o grafo pode ser desconexo, `dis[i][j]` pode continuar `INF` no final — sempre checar antes de somar ou imprimir, senão o resultado fica poluído por um valor gigante.
- [ ] **Casos Base / Sentinela:** Como o código se comporta para $N = 0$, $N = 1$, ou grafo sem nenhuma aresta?
- [ ] **Limpeza de Memória (Múltiplos Testes):** A matriz `dis[][]` precisa ser reinicializada (não só a parte usada — cuidado se o tamanho do grafo muda entre casos de teste) a cada novo caso.
- [ ] **Índices (0-based vs 1-based):** A indexação do problema bate com a lógica do loop? (nós numerados de 1 a N vs array 0-indexado)

---

## 🎯 Problemas Práticos

| Problema                                                                                                                                  | Juiz            | Dificuldade |    Status    | Notas / Pegadinhas                                                                                                                            |
| :---------------------------------------------------------------------------------------------------------------------------------------- | :-------------- | :---------: | :----------: | :-------------------------------------------------------------------------------------------------------------------------------------------- |
| **[Page Hopping (UVA 821)](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=762)** | UVA             |  🟢 Fácil   |   🔲 FEITA   | Múltiplos casos de teste; nós não contíguos entre 1 e 100; média sobre pares (i,j) com i≠j; grafo garantido conexo (todo nó alcança todo nó). |
| **[Nome do Problema](Link)**                                                                                                              | CSES            |  🟡 Média   | 🔲 Pra fazer | Exige adaptação nos limites ou tipo de dados.                                                                                                 |
| **[Nome do Problema](Link)**                                                                                                              | SPOJ / LeetCode | 🔴 Difícil  | 🔲 Pra fazer | Combina este algoritmo com outra técnica (ex: PD / Busca Binária).                                                                            |

---
## 🔄 Histórico de Revisão & Erros Comuns
* *Anotações pessoais de onde você já errou esse algoritmo em simulados ou contestações passadas.*
* Erro comum: atualizar `dis[i][k]` no lugar de `dis[i][j]` dentro do triplo loop (troca de índice na hora de escrever a fórmula na pressa).
