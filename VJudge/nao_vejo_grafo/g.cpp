#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int di[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dj[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int i, int j, int n, vector<vector<char>> &adj) {
  adj[i][j] = '0';

  for (int k = 0; k < 8; k++) {
    int ii = i + di[k];
    int jj = j + dj[k];

    if (ii >= 0 && ii < n && jj >= 0 && jj < n && adj[ii][jj] == '1') {
      dfs(ii, jj, n, adj);
    }
  }
}

void solve() {
  int n;
  int img = 1;

  while (cin >> n) {
    vector<vector<char>> adj(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> adj[i][j];
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][j] == '1') {
          ans++;
          dfs(i, j, n, adj);
        }
      }
    }

    cout << "Image number " << img++ << " contains " << ans << " war eagles."
         << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
