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

  for (int i = 2; i <= n; i++) {
    int chefe;
    cin >> chefe;

    adj[chefe].push_back(i);
  }

  vector<int> sub(n + 1, 0);
  auto dfs = [&](auto &&self, int u) -> void {
    for (auto v : adj[u]) {
      self(self, v);
      sub[u] += 1 + sub[v];
    }
  };

  dfs(dfs, 1);

  for (int i = 1; i <= n; i++) {
    cout << sub[i] << (i == n ? "\n" : " ");
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
