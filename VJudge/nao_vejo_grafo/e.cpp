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
  string max_s;
  cin >> max_s;
  cin.ignore(256, '\n');

  int n = max_s[0] - 'A' + 1;

  vector<vector<int>> adj(n);
  string edge;

  while (getline(cin, edge) && !edge.empty() && edge != "\r") {
    int u = edge[0] - 'A';
    int v = edge[1] - 'A';

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> vis(n, false);

  function<void(int)> dfs = [&](int u) -> void {
    vis[u] = true;
    for (int v : adj[u]) {
      if (vis[v])
        continue;
      dfs(v);
    }
  };

  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
      ans++;
    }
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
    if (t > 0)
      cout << endl;
  }

  return 0;
}
