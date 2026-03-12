#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n, W;
  cin >> n >> W;
  W++;
  n++;

  vector<vector<int>> pd(n, vector<int>(W, -1));

  fill(pd[0].begin(), pd[0].end(), 0);

  for (int i = 1; i < n; i++) {
    int w, v;
    cin >> w >> v;

    for (int j = 0; j < W; j++) {
      if (w > j)
        pd[i][j] = pd[i - 1][j];
      else
        pd[i][j] = max(pd[i - 1][j], pd[i - 1][j - w] + v);

      // cout << pd[i][j] << '\t';
    }

    // cout << endl;
  }

  cout << pd[n - 1][W - 1] << endl;
}
