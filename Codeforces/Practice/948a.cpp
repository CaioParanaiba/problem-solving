#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  cin >> r >> c;

  vector<vector<char>> grid(r, vector<char>(c));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '.')
        grid[i][j] = 'D';
    }
  }

  bool possivel = true;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 'W') {
        for (int k = 0; k < 4; k++) {
          int ii = i + di[k];
          int jj = j + dj[k];
          if (ii >= 0 && ii < r && jj >= 0 && jj < c && grid[ii][jj] == 'S')
            possivel = 0;
        }
      }
    }
  }

  if (possivel) {
    cout << "YES\n";
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << grid[i][j];
      }
      cout << endl;
    }
  } else
    cout << "NO\n";
}
