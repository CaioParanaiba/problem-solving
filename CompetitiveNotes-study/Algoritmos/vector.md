---
aliases: [std::vector, Dynamic Array]
tags: #stl #cp4 #estrutura #primitiva
data_criacao: 2024-01-15
status: consolidado
---

# 📚 vector

**MOC:** [[MOC - Estruturas de Dados]]
**Pré-requisitos:** C++ Básico

---

## 💡 O que é? (O Insight)
Array dinâmico contíguo em memória. É a estrutura fundamental da programação competitiva devido ao uso otimizado de cache do processador (localidade de referência) e baixíssima constante oculta.

---

## ⏱️ Complexidade dos Métodos

| Método                            | Complexidade                         | Uso em Maratona                               |
| --------------------------------- | ------------------------------------ | --------------------------------------------- |
| `.push_back(val)` / `.pop_back()` | $O(1)$ amortizado                    | Inserção e remoção no final                   |
| `v[i]`                            | $O(1)$                               | Acesso aleatório direto                       |
| `.insert(it, val)` / `.erase(it)` | $O(N)$                               | Inserção ou remoção no meio (evite ao máximo) |
| `.size()` / `.empty()`            | $O(1)$                               | Verificação de estado                         |
| `.clear()`                        | $O(N)$ destruição / $O(1)$ ponteiros | Limpa elementos mantendo a capacidade alocada |

---

## ⚠️ Pegadinhas Clássicas e Edge Cases

- [ ] **TLE por cópia de parâmetro:** Declarar funções como `void dfs(int u, vector<int> adj)` copia todo o vetor a cada chamada recursiva, gerando TLE em $O(N^2)$. Sempre passe por referência: `const vector<int>& v`.

- [ ] **A Armadilha do `vector<bool>`:** A STL otimiza espaço (1 bit por bool) retornando um objeto *proxy*, não uma referência real `bool&`. Isso quebra laços `auto&`, falha com `std::swap` e degrada performance. Use `vector<int>`, `vector<char>` ou `bitset`.

- [ ] **Realocação dinâmica:** Se o tamanho final for conhecido, use `v.reserve(N)` ou declare o tamanho no construtor `vector<int> v(N)` para evitar realocações sucessivas.

---

## 💻 Snippet de Ouro: Compressão de Coordenadas

Mapeia valores esparsos de até $10^{18}$ para o intervalo compacto $[0, N)$, essencial para alimentar Segment Trees ou Fenwick Trees.

```cpp
vector<long long> vals = { /* valores brutos */ };
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());

// Para encontrar o índice comprimido de 'x' em O(log N):
int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
```

---

## 🎯 Problemas Práticos

| Problema | Juiz | Dificuldade | Status | Notas / Pegadinhas |
| :--- | :--- | :---: | :---: | :--- |
| *(A ser preenchido)* | - | - | - | Compressão de coordenadas, ordenação customizada |

---

## 🔄 Histórico de Revisão & Erros Comuns
* *Anotações pessoais de erros em simulados.* 
