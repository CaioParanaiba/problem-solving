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
  int n, m, l;
  cin >> n >> m >> l;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  vector<bool> vis(n + 1, 0);
  int ans = 0;

  function<void(int)> dfs = [&](int u) {
    vis[u] = true;
    ans++;

    for (auto v : adj[u]) {
      if (vis[v])
        continue;
      dfs(v);
    }
  };

  for (int i = 0; i < l; i++) {
    int a;
    cin >> a;
    if (!vis[a])
      dfs(a);
  }

  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
