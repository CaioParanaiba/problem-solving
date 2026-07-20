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

  vector<vector<char>> mat(n, vector<char>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> mat[i][j];
  }

  vector<vector<int>> vis(n, vector<int>(m, 0));

  int di[4] = {1, -1, 0, 0};
  int dj[4] = {0, 0, 1, -1};

  bool ans = false;

  auto dfs = [&](auto &&self, int i, int j, int pi, int pj) -> void {
    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
      int ii = i + di[k];
      int jj = j + dj[k];

      if (ii >= 0 && jj >= 0 && ii < n && jj < m && mat[ii][jj] == mat[i][j]) {
        if ((ii != pi || jj != pj) && vis[ii][jj])
          ans = true;
        if (vis[ii][jj])
          continue;

        self(self, ii, jj, i, j);
      }
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j])
        dfs(dfs, i, j, -1, -1);
    }
  }

  cout << (ans ? "Yes\n" : "No\n");
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
