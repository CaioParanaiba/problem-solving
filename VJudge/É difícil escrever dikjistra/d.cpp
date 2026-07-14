#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1005;
const int INF = 1e18;

int mat[MAXN][MAXN];
int dis[MAXN][MAXN];

signed main() {
  int t;
  cin >> t;

  int di[4] = {1, -1, 0, 0};
  int dj[4] = {0, 0, 1, -1};

  while (t--) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
        dis[i][j] = INF;
      }
    }

    dis[0][0] = mat[0][0];

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({dis[0][0], {0, 0}});

    while (pq.size()) {
      auto [w, ij] = pq.top();
      auto [i, j] = ij;
      pq.pop();

      if (w > dis[i][j])
        continue;

      for (int k = 0; k < 4; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];

        if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
          int custo = dis[i][j] + mat[ii][jj];
          if (custo < dis[ii][jj]) {
            dis[ii][jj] = custo;
            pq.push({dis[ii][jj], {ii, jj}});
          }
        }
      }
    }

    cout << dis[n - 1][m - 1] << "\n";
  }
}
