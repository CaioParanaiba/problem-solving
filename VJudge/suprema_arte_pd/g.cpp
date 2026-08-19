#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  vector<int> pd(n + 1, -1);

  auto busca = [&](auto &self, int u) -> int {
    if (pd[u] != -1)
      return pd[u];
    pd[u] = 0;
    for (auto v : adj[u]) {
      pd[u] = max(self(self, v) + 1, pd[u]);
    }

    return pd[u];
  };

  for (int i = 1; i <= n; i++) {
    if (pd[i] != -1)
      continue;
    busca(busca, i);
  }

  int ans = 0;
  for (auto i : pd) {
    ans = max(ans, i);
  }

  cout << ans << endl;
}
