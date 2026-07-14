Tags: #stl #cp4 #estrutura #primitiva #bst #map
Pré-requisitos: C++ Básico
MOC: [[MOC - ED]]

## 💡 O que é? (O Insight)
Mapeamento associativo ordenado (`Chave -> Valor`) implementado sobre uma **Red-Black Tree**. Mantém as chaves estritamente ordenadas de forma automática, permitindo buscas, inserções e remoções logarítmicas.

*Aviso de Maratona:* A constante oculta do `map` é significativamente alta devido à alocação dinâmica e fragmentação de memória dos nós. Só use `map` se as chaves forem esparsas (ex: $10^{18}$ ou strings) **E** você precisar das chaves ordenadas ou atualizações dinâmicas. Caso contrário, use [[vector]] com compressão de coordenadas ou [[unordered_map]] com custom hash.

## ⏱️ Complexidade dos Métodos
| Método | Complexidade | Uso em Maratona |
|---|---|---|
| `mp[key] = val` | $O(\log N)$ | Acesso, criação ou atualização de chave |
| `.find(key)` / `.count(key)` | $O(\log N)$ | Busca binária sem efeito colateral (não aloca memória) |
| `.erase(key)` / `.erase(it)` | $O(\log N)$ / $O(1)$ amortizado | Remove um par chave-valor pela chave ou pelo iterador |
| `.lower_bound(key)` | $O(\log N)$ | Busca binária direta pela **chave** ($\ge key$) |
| `.upper_bound(key)` | $O(\log N)$ | Busca binária direta pela **chave** ($> key$) |

## ⚠️ Gotchas & Edge Cases (Onde quebra)
- **Vazamento Silencioso de Memória (MLE/TLE via Operador `[]`):** Este é um dos maiores causadores de erros silenciosos em maratona. Escrever `if (mp[key] == 10)` em uma chave que **não existe** faz o C++ **criar e inserir imediatamente** o par `{key, 0}` no `map`. Se você fizer isso dentro de um laço verificando $10^5$ posições inexistentes, seu `map` explodirá de tamanho, alocando memória desnecessária (MLE) e rebalanceando a árvore sem parar (TLE).
  - *Correção:* Para verificar existência sem modificar a estrutura, use **exclusivamente**: `if (mp.find(key) != mp.end())` ou `if (mp.count(key))`.

- **TLE por Chamada da Função Global `std::lower_bound`:** Assim como no `set`, nunca chame `std::lower_bound(mp.begin(), mp.end(), x)`. Isso roda em tempo linear **$O(N)$**. Chame sempre o método da classe: `mp.lower_bound(x)` em **$O(\log N)$

- **Erro de Compilação por Tentar Alterar Chave no Laço:** Em um laço `for (auto& [k, v] : mp)`, a variável `k` (chave) é implicitamente `const`. Tentar fazer `k++` gera erro imediato de compilação.

- **Armadilha do Tipo do Valor Padrão no `[]`:** Quando o `mp[key]` cria um valor não existente, ele invoca o construtor padrão do tipo do valor. Para `int`, `long long` ou `double`, é sempre zero (`0` / `0.0`). Para ponteiros, pode ser lixo ou `nullptr`.

## 💻 Snippet de Ouro: Frequência Esparsa e Structured Binding
Técnica padrão para contar frequências de chaves grandes ($10^{18}$ ou strings) sem precisar de compressão de coordenadas e iterando pelos elementos de forma limpa em C++17.

```cpp
#include <bits/stdc++.h>
using namespace std;

void exemplo_map() {
    map<long long, int> freq;
    vector<long long> a = {1000000000000LL, 50, 1000000000000LL, 50, 50};

    // 1. Contagem segura
    for (long long x : a) {
        freq[x]++; // Seguro usar [] na inserção/atualização intencional
    }

    // 2. Consulta SEGURA sem alocar lixo em chaves inexistentes
    long long chave_busca = 999;
    if (freq.find(chave_busca) != freq.end()) {
        cout << "Achei: " << freq[chave_busca] << "\n";
    } else {
        cout << "Nao existe, e o map continua do mesmo tamanho!\n";
    }

    // 3. Iteração limpa com C++17 (Structured Binding)
    // Garanta que está na ordem CRESCENTE das chaves automaticamente
    for (const auto& [chave, contagem] : freq) {
        cout << chave << " -> " << contagem << " vezes\n";
    }
}
```

## Problemas Práticos & Ligações

- Alternativa simples para [[Compressão de Coordenadas]] quando o tempo do problema é generoso com o fator $O(\log N)$.

- [[Digit DP]] ou Memoização de Programação Dinâmica em grafos de estados complexos (onde o estado da DP é uma string, um vetor, ou uma matriz inteira: `map<vector<int>, int> memo`).

- [[Algoritmo de Mo]] ou problemas de contagem de prefixos esparsos (ex: quantidade de subarrays cuja soma é igual a $K$ em matrizes com números negativos).