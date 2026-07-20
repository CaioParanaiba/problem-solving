#include <bits/stdc++.h>
#include <iostream>
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

  vector<string> adj(n);
  for (int i = 0; i < n; i++)
    cin >> adj[i];

  vector<string> adj2 = adj;

  int di[4] = {1, -1, 0, 0};
  int dj[4] = {0, 0, 1, -1};

  auto dfs = [&](auto &&self, int i, int j) -> void {
    adj[i][j] = '#';

    for (int k = 0; k < 4; k++) {
      int ii = i + di[k];
      int jj = j + dj[k];

      if (ii >= 0 && ii < n && jj >= 0 && jj < m && adj[ii][jj] == '.') {
        self(self, ii, jj);
      }
    }
  };

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (adj[i][j] == '.') {
        dfs(dfs, i, j);
        ans++;
      }
    }
  }

  cout << ans << endl;
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
