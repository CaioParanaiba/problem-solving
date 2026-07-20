---
aliases: [std::unordered_map, Hash Map, Hash Table]
tags: #stl #cp4 #estrutura #primitiva #hash #unordered_map
data_criacao: 2024-01-15
status: consolidado
---

# 📚 unordered_map

**MOC:** [[MOC - Estruturas de Dados]]
**Pré-requisitos:** C++ Básico

---

## 💡 O que é? (O Insight)
Tabelas Hash (*Hash Tables*) associativas. Não mantêm nenhuma ordem entre os elementos, mas prometem acesso, inserção e busca instantâneos no caso médio, usando uma função de espalhamento (hash) para indexar *buckets* de memória.
*Aviso de Maratona:* A STL usa tratamento de colisões por encadeamento (*chaining*). Se muitos elementos caírem no mesmo bucket, a busca se degrada para uma lista encadeada linear.

---

## ⏱️ Complexidade dos Métodos

| Método | Complexidade | Uso em Maratona |
|---|---|---|
| `.insert(val)` / `mp[key]` | $O(1)$ médio / $O(N)$ pior caso | Inserção rápida no caso médio |
| `.find(key)` / `.count(key)` | $O(1)$ médio / $O(N)$ pior caso | Verificação de existência sem alocar memória lixo |
| `.erase(key)` | $O(1)$ médio / $O(N)$ pior caso | Remoção por chave |
| `.reserve(N)` | $O(N)$ alocação | Pré-aloca *buckets* para evitar re-hashing durante o código |
| `.max_load_factor(0.25)` | $O(1)$ | Força a tabela a dobrar de tamanho com menos colisões |

---

## ⚠️ Pegadinhas Clássicas e Edge Cases

- [ ] **A Vulnerabilidade Fatal (Anti-Hash TLE no Codeforces/ICPC):** A função hash nativa do C++ para números inteiros é a identidade matemática ($hash(X) = X$). Em plataformas competitivas modernas, os juízes incluem testes maliciosamente projetados com milhares de números congruentes ao módulo de tamanho da tabela. Isso faz **todos** os elementos colidirem no mesmo bucket, transformando a complexidade de tempo de $O(1)$ para um **$O(N)$ catastrófico por operação**, garantindo TLE.
  - *Correção de Maratona:* **Nunca** use `unordered_map` nativo com chaves inteiras em competições sem injetar um Custom Hash seguro baseado no relógio da CPU. Se o limite de tempo do problema for generoso com o fator logarítmico, prefira usar `std::map`.

- [ ] **Vazamento Silencioso via Operador `[]`:** Exatamente igual ao `std::map`, fazer `if (mp[key] == 10)` em uma chave inexistente aloca memória e insere o par `{key, 0}` na tabela hash. Use **sempre** `mp.find(key) != mp.end()` para checar existência sem efeito colateral.

- [ ] **Overhead de Re-hashing Dinâmico:** Quando a tabela enche e ultrapassa o *load factor* padrão (1.0), ela aloca uma tabela nova com o dobro de buckets e recalcula o hash de todos os elementos em $O(N)$. Para evitar esse overhead no meio da execução, chame `mp.reserve(N)` logo após declarar a estrutura se você souber a quantidade aproximada de inserções.

- [ ] **Inexistência para Tipos Complexos (Pares, Vetores e Structs):** Tentar declarar um `unordered_map<pair<int, int>, int>` causa **Erro de Compilação (CE)** imediato. Diferente do `std::map` (que usa operador `<`), a tabela hash exige uma função de hash específica, e a STL nativa do C++ não fornece um hash padrão para `std::pair` ou `std::vector`.

---

## 💻 Snippet de Ouro: Custom Hash Blindado (SplitMix64)

Injeta entropia do relógio de alta precisão do processador (*ASLR - Address Space Layout Randomization*) no algoritmo de espalhamento SplitMix64, tornando matematicamente impossível para um gerador de testes prever colisões contra seu código.

```cpp
#include <bits/stdc++.h>
using namespace std;

// 1. Estrutura de Hash Blindada contra Anti-Hash Tests
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // Algoritmo de dispersão de bits ultra rápido
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        // Semente fixa gerada 1 vez por execução usando o relógio da CPU
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void exemplo_seguro() {
    // 2. Declaração à prova de TLE para competições:
    unordered_map<long long, int, custom_hash> mp_seguro;
    unordered_set<long long, custom_hash> st_seguro;

    // 3. Otimização máxima de performance em contest:
    int n_estimado = 200000;
    mp_seguro.reserve(n_estimado); // Aloca buckets suficientes de uma vez
    mp_seguro.max_load_factor(0.25); // Diminui colisão forçando tabelas mais vazias
    
    mp_seguro[1000000000000LL] = 42;
    if (mp_seguro.find(1000000000000LL) != mp_seguro.end()) {
        cout << "Seguro, rápido em O(1) real e imune a Anti-Hash!\n";
    }
}
```

---

## 🎯 Problemas Práticos

| Problema | Juiz | Dificuldade | Status | Notas / Pegadinhas |
| :--- | :--- | :---: | :---: | :--- |
| [[Sliding Window]] | - | - | - | Contagem $O(1)$ de elementos distintos em janelas |
| [[Two Pointers]] | - | - | - | Técnica complementar para janelas dinâmicas |
| [[Memoização]] | - | - | - | DP com domínio esparso e linear em tempo |

**Ligações:** BFS em problemas de alta dimensionalidade (8-Puzzle, matrizes compactadas em bitmask).

---

## 🔄 Histórico de Revisão & Erros Comuns
* *Anotações pessoais de erros em simulados.*