#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

  int grid[999][999];

  int di[] = {0, 0, -1, 1};
  int dj[] = {-1, 1, 0, 0};

  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        grid[i][j] = x;
      }
    }

    vector<vector<int>> d(n, vector<int>(m, 1e9));
    d[0][0] = grid[0][0];

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;

    pq.push({grid[0][0], 0, 0});
    while (pq.size()) {
      auto [w, i, j] = pq.top();
      pq.pop();
      for (int l = 0; l < 4; l++) {
        int ii = i + di[l];
        int jj = j + dj[l];

        if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
          ll wij = grid[ii][jj];
          if (w + wij < d[ii][jj]) {
            d[ii][jj] = w + wij;
            pq.push({d[ii][jj], ii, jj});
          }
        }
      }
    }

    cout << d[n - 1][m - 1] << '\n';
  }

  return 0;
}
