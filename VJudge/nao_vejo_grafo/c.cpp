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

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> vis(n + 1, 0);

  auto dfs = [&](auto &&self, int u) -> void {
    vis[u] = true;
    for (auto v : adj[u]) {
      if (vis[v])
        continue;
      self(self, v);
    }
  };

  int ans = 0;
  dfs(dfs, 1);
  vis[1] = true;

  vector<pair<int, int>> resp;
  for (int i = 2; i <= n; i++) {
    if (vis[i])
      continue;
    ans++;
    resp.push_back({i - 1, i});
    dfs(dfs, i);
  }

  cout << ans << endl;
  for (auto i : resp) {
    cout << i.first << ' ' << i.second << endl;
  }
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
