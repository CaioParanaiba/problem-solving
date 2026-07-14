#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  vector<long double> dis(n + 1, 1e18);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  priority_queue<pair<long double, int>, vector<pair<long double, int>>,
                 greater<pair<long double, int>>>
      pq;
  dis[1] = 0;
  pq.push({0, 1});

  while (pq.size()) {
    auto [w, u] = pq.top();
    pq.pop();

    if (w > dis[u])
      continue;

    for (auto [wv, v] : adj[u]) {

      long double log_costo = log10(wv) / log10(7);

      if (dis[u] + log_costo < dis[v]) {
        dis[v] = dis[u] + log_costo;
        pq.push({dis[v], v});
      }
    }
  }

  printf("%.10lf\n", (double)dis[n]);
}
