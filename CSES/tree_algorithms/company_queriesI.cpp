#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  int limit = log2(n) + 1;

  vector<vector<int>> mat(n + 1, vector<int>(limit));

  mat[1][0] = -1;

  for (int i = 2; i <= n; i++) {
    cin >> mat[i][0];
  }

  for (int j = 1; j < limit; j++) {
    for (int i = 1; i <= n; i++) {
      if (mat[i][j - 1] == -1)
        mat[i][j] = -1;
      else
        mat[i][j] = mat[mat[i][j - 1]][j - 1];
    }
  }

  while (q--) {
    int x, k;
    cin >> x >> k;

    for (int i = limit - 1; i >= 0; i--) {
      if (x == -1)
        break;
      if (k & (1LL << i)) {
        x = mat[x][i];
      }
    }

    cout << x << ' ';
  }
  cout << endl;
}
