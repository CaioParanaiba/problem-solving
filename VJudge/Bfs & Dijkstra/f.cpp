#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int cs;
  cin >> cs;

  for (int i = 0; i < cs; i++) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<pair<int, int>> adj[n];
    for (int j = 0; j < m; j++) {
      int a, b, w;
      cin >> a >> b >> w;
      adj[a].push_back({w, b});
      adj[b].push_back({w, a});
    }

    vector<int> d(n, 1e9);
    d[s] = 0;
    vector<int> pai(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, s});

    while (pq.size()) {
      auto [w, v] = pq.top();
      pq.pop();

      if (w > d[v])
        continue;
      for (auto [wu, u] : adj[v]) {
        if (wu + w < d[u]) {
          d[u] = wu + w;
          pq.push({d[u], u});
          pai[u] = v;
        }
      }
    }

    cout << "Case #" << i + 1 << ": ";

    if (pai[t] != -1)
      cout << d[t];
    else
      cout << "unreachable";
    cout << '\n';
  }

  return 0;
}
