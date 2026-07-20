#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<bool> vis(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  auto dfs = [&](auto &&self, int u, bool &ans) -> void {
    vis[u] = true;

    if (adj[u].size() != 2)
      ans = false;
    for (auto v : adj[u]) {
      if (vis[v])
        continue;
      self(self, v, ans);
    }
  };

  int count = 0;
  for (int i = 1; i <= n; i++) {
    bool ans = true;
    if (vis[i])
      continue;
    dfs(dfs, i, ans);
    if (ans)
      count++;
  }

  cout << count << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
