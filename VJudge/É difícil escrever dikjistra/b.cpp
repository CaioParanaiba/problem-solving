#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 100005;

signed main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> adj[MAXN];
  int dis[MAXN];

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back({b, c});
  }

  for (int i = 1; i <= n; i++)
    dis[i] = INF;

  dis[1] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({dis[1], 1});

  while (pq.size()) {
    auto [wu, u] = pq.top();
    pq.pop();

    if (wu > dis[u])
      continue;

    for (auto [v, wv] : adj[u]) {
      int custo = wv + dis[u];
      if (custo < dis[v]) {
        dis[v] = custo;
        pq.push({dis[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dis[i] << (i == n ? "\n" : " ");
  }
}
