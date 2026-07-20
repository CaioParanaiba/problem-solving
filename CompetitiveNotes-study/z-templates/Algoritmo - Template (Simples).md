---
aliases: []
tags: #cp #algoritmo #obi #icpc
data_criacao: <% tp.file.creation_date("YYYY-MM-DD") %>
status: a_revisar
---

# 📚 <% tp.file.title %>

**MOC:** <% tp.file.cursor(1) %>
**Pré-requisitos:** <% tp.file.cursor(2) %>
**Autor:** <% tp.file.cursor(3) %>

---

## 💡 O que é? (O Insight)
> [!SUMMARY] Resumo Rápido
> Explicação em 1 ou 2 frases sobre a ideia central do algoritmo e para que categoria de problemas ele serve.

* **O Problema:** Qual é o gargalo da abordagem ingênua (ex: $\mathcal{O}(N^2)$ por força bruta)?
* **O Insight Clave:** Como essa estrutura/algoritmo quebra o gargalo e otimiza a transição de estado ou busca?

---

## ⚙️ Como funciona? (Passo a Passo)

1. **Estado Inicial:** Como as variáveis, estruturas ou ponteiros começam.
2. **Transição / Processamento:** A regra principal do loop ou recursão.
3. **Condição de Parada / Otimização:** Como evitamos trabalho desnecessário ou fechamos o ciclo.

---

## ⏱️ Análise de Complexidade

| Medida | Complexidade | Explicação / Justificativa |
| :--- | :---: | :--- |
| **Tempo (Pré-processamento)** | **$\mathcal{O}(...)$** | Custo para construir a estrutura inicial (ex: ordenação, build de árvore). |
| **Tempo (Por Query/Iteração)** | **$\mathcal{O}(...)$** | Custo operacional amortizado ou no pior caso. |
| **Espaço (Memória Auxiliar)** | **$\mathcal{O}(...)$** | Consumo extra de memória RAM (vetores, pilha de recursão). |

---

## 💻 Código Base (Módulo / Função Limpa)

> [!TIP] Dica de Contest
> Implementação modular e flexível. Evite código engessado em `main()`; prefira funções limpas, lambdas ou structs fáceis de adaptar para diferentes formatos de entrada.

```cpp
#include <bits/stdc++.h>
using namespace std;

// === [ NOME DO ALGORITMO / FUNÇÃO ] ===
// Descrição breve dos parâmetros e retorno.
// Tempo: O(...) | Espaço: O(...)



```

---

## ⚠️ Pegadinhas Clássicas e Edge Cases (Checklist de Contest)

- [ ] **Overflow (32 vs 64 bits):** Operações intermediárias podem estourar `int`? Necessário `long long`?
- [ ] **Casos Base / Sentinela:** Como o código se comporta para $N = 0$, $N = 1$, ou todos os elementos iguais/zeros?
- [ ] **Passagem por Referência:** Vetores ou strings grandes estão sendo passados com `const vector<T>&` para evitar TLE de cópia?
- [ ] **Limpeza de Memória (Múltiplos Testes):** Estruturas globais ou vetores são limpos de um caso de teste para outro (`clear()`, `assign()`)?
- [ ] **Índices (0-based vs 1-based):** A indexação do problema bate com a lógica do loop?

---

## 🎯 Problemas Práticos

| Problema | Juiz | Dificuldade | Status | Notas / Pegadinhas |
| :--- | :--- | :---: | :---: | :--- |
| **[Nome do Problema](Link)** | Codeforces | 🟢 Fácil | 🔲 Pra fazer | Foco na implementação básica do conceito. |
| **[Nome do Problema](Link)** | CSES | 🟡 Média | 🔲 Pra fazer | Exige adaptação nos limites ou tipo de dados. |
| **[Nome do Problema](Link)** | SPOJ / LeetCode | 🔴 Difícil | 🔲 Pra fazer | Combina este algoritmo com outra técnica (ex: PD / Busca Binária). |

---
## 🔄 Histórico de Revisão & Erros Comuns
* *Anotações pessoais de onde você já errou esse algoritmo em simulados ou contestações passadas.*
