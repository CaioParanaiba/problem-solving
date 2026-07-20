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

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> map(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> map[i][j];
  }

  vector<vector<int>> dis(n, vector<int>(m, 1e18));
  dis[0][0] = 0;

  deque<pair<int, int>> dq;
  dq.push_back({0, 0});

  while (dq.size()) {
    auto [i, j] = dq.front();
    dq.pop_front();

    for (int k = 0; k < 4; k++) {
      int ii = i + di[k];
      int jj = j + dj[k];

      if (ii >= 0 && jj >= 0 && ii < n && jj < m) {
        int custo = (map[ii][jj] == map[i][j]) ? 0 : 1;
        if (dis[ii][jj] > dis[i][j] + custo) {
          dis[ii][jj] = dis[i][j] + custo;
          if (custo)
            dq.push_back({ii, jj});
          else
            dq.push_front({ii, jj});
        }
      }
    }
  }

  cout << dis[n - 1][m - 1] << endl;
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
