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
int c = 1;
int di[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dj[8] = {-1, 0, 1, -1, 0, 1, 1, -1};

void solve() {
  int r1, c1, r2, c2, r3, c3;
  while (cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3) {
    vector<vector<int>> adj(9, vector<int>(9, 0));
    vector<vector<bool>> vis(9, vector<bool>(9, 0));
    vis[r3][c3] = true;

    queue<pair<int, int>> q;
    q.push({r1, c1});
    vis[r1][c1] = true;

    while (q.size()) {
      auto [i, j] = q.front();
      q.pop();

      for (int k = 0; k < 8; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];

        if (ii >= 1 && jj >= 1 && ii < 9 && jj < 9 && !vis[ii][jj]) {
          adj[ii][jj] = adj[i][j] + 1;
          q.push({ii, jj});
          vis[ii][jj] = true;
        }
      }
    }

    cout << "Case " << c++ << ": " << adj[r2][c2] << endl;
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
