#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n;
  cin >> n;
  vector<vector<int>> dp(n, vector<int>(3));

  int a;
  for (int i = 0; i < 3; i++) {
    cin >> a;
    dp[0][i] = a;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a;
      dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + a;
    }
  }

  int resultado = max(dp[n - 1][0], dp[n - 1][1]);
  resultado = max(resultado, dp[n - 1][2]);
  cout << resultado;
  cout << endl;
}
