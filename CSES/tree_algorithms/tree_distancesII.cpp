#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> sz(n + 1, 0), ans(n + 1, 0);

  auto dfs1 = [&](auto &&self, int u, int p, int prof) -> void {
    sz[u] = 1;
    ans[1] += prof;

    for (auto v : adj[u]) {
      if (v == p)
        continue;
      self(self, v, u, prof + 1);
      sz[u] += sz[v];
    }
  };

  auto dfs2 = [&](auto &&self, int u, int p) -> void {
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      ans[v] = ans[u] - sz[v] + (n - sz[v]);
      self(self, v, u);
    }
  };

  dfs1(dfs1, 1, 1, 0);
  dfs2(dfs2, 1, 1);

  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}
