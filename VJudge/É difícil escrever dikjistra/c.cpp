#include <bits/stdc++.h>
#include <ios>

using namespace std;

#define int long long
const int INF = 1e18;
const int MAXN = 100005;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> adj[MAXN];
  int dis[MAXN];
  int pai[MAXN];

  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  for (int i = 0; i < n; i++)
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
        pai[v] = u;
        dis[v] = custo;
        pq.push({dis[v], v});
      }
    }
  }

  vector<int> vis(MAXN, 0);
  queue<int> bfs;
  int pai_bfs[MAXN];

  vis[0] = 1;
  bfs.push(0);

  while (bfs.size()) {
    int u = bfs.front();
    bfs.pop();

    for (auto [v, wv] : adj[u]) {
      if (pai[u] != v && !vis[v]) {
        vis[v] = 1;
        bfs.push(v);
        pai_bfs[v] = u;
      }
    }
  }

  if (vis[1]) {
    stack<int> caminho;
    caminho.push(1);

    while (caminho.top() != 0) {
      int p = caminho.top();
      caminho.push(pai_bfs[p]);
    }

    cout << caminho.size() << " ";
    while (caminho.top() != 1) {
      cout << caminho.top() << " ";
      caminho.pop();
    }
    cout << 1 << endl;
  } else
    cout << "impossible\n";
}
