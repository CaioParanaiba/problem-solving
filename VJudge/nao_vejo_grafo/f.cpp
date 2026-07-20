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
  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> vis(n + 1, 0);
  vector<bool> cor(n + 1, 0);

  int semcor = 1, comcor = 0;

  auto dfs = [&](auto &&self, int u) -> void {
    vis[u] = true;

    for (auto v : adj[u]) {
      if (vis[v])
        continue;

      cor[v] = !cor[u];

      (cor[v]) ? comcor++ : semcor++;

      self(self, v);
    }
  };

  vis[1] = true;

  dfs(dfs, 1);

  cout << semcor * comcor - (n - 1) << endl;
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
