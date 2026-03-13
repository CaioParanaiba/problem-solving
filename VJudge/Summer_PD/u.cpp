#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int MOD = 1e9 + 7;

signed main() {

  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    coins[i] = c;
  }

  sort(coins.begin(), coins.end());

  vector<int> pd(x + 1, 0);
  pd[0] = 1;

  for (int i = 1; i <= x; i++) {
    for (auto c : coins) {
      if (i - c < 0)
        break;
      pd[i] += pd[i - c];
      pd[i] %= MOD;
    }
  }

  cout << pd[x] << endl;
}
