
**Tags:** #grafos #cp4 #algoritmo 
**Pré-requisitos:** [[priority_queue]], [[BFS]]
**MOC**:[[MOC - Grafos]]
**Autor:** [[Edsger Disjktra]]

> [!abstract] 💡 O que é? (O Insight)
> É uma [[BFS]] otimizada usando para calcular o *menor caminho* dentro de um GRAFO
> Um dos poucos algoritmos [[Guloso|gulosos]] que é comprovadamente a melhor solução
> Ele funciona apenas com pesos não negativos

## ⚙️ Como funciona? (Passo a Passo)
1. Definimos os adj (adjacentes, na forma: `adj[u].push_back({v,w})`) com n+1 posições;
2. para cada nó definimos uma distancia (dis) com valores muito altos (1e18 ou 1e9) com n+1 posições;
3. Declaramos a [[priority_queue]] e fazemos ela ordenar pelo  `greater`;
4. Definimos os parametros iniciais;
5. Rodamos nosso algoritmo, de forma similar a [[BFS]];

## ⏱️ Complexidade
* **Tempo:** $O(E\space log(V))$ 
* **Espaço:** $O(E\space + \space V)$ 

## 💻 Código Base
```c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18; // Requer long long

// Adjacência armazenando {destino, peso}
// adj[u].push_back({v, w});
vector<pair<int, long long>> adj[100005]; 
long long dis[100005];

void dijkstra(int inicial) {
    // Fila de prioridade: pair<distancia, vertice>
    // Usamos greater para ser uma Min-Heap (menor distância no topo)
    priority_queue< pair<long long, int>, 
                    vector<pair<long long, int>>, 
                    greater<pair<long long, int>> > pq;

    // Inicializa as distâncias como infinito
    // Lembre-se de preencher até o número exato de nós (ex: N)
    for(int i = 0; i <= 100000; i++) dis[i] = INF;

    dis[inicial] = 0;
    pq.push({0, inicial});

    while (!pq.empty()) {
        auto [wu, u] = pq.top();
        pq.pop();
        
        // Poda essencial: se encontrarmos um caminho desatualizado na fila, ignoramos
        if (wu > dis[u]) continue; 
        
        // v = vértice destino, w = peso da aresta
        for (auto [v, wv] : adj[u]) {
            long long custo = dis[u] + wv;
            
            if (custo < dis[v]) {
                dis[v] = custo;
                pq.push({dis[v], v});
            }
        }
    }
}
```

## 🎯 Problemas Práticos
[X] https://codeforces.com/gym/104415/problem/J - uso de log