#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define ll long long

int main() {

  int n, m;
  cin >> n >> m;

  vector<pair<ll, int>> adj[n + 1];
  vector<ll> d(n + 1, 1e18);
  d[1] = 0;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;

  pq.push({0, 1});

  while (pq.size()) {
    auto [w, v] = pq.top();
    pq.pop();

    if (w > d[v])
      continue;

    for (auto [wu, u] : adj[v]) {
      if (w + wu < d[u]) {
        d[u] = wu + w;
        pq.push({d[u], u});
      }
    }
  }

  string sp = "";
  for (int i = 1; i <= n; i++) {
    cout << sp << d[i];
    sp = " ";
  }
  cout << '\n';

  return 0;
}
