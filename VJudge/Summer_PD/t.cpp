#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int t, n;
  cin >> t >> n;

  vector<int> coins(t);
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    coins[i] = x;
  }

  vector<int> pd(n + 1);
  pd[0] = 0;

  for (int i = 1; i <= n; i++) {
    pd[i] = 1e18;
    for (auto c : coins) {
      if (i - c >= 0)
        pd[i] = min(pd[i], pd[i - c] + 1);
    }
  }

  if (pd[n] == 1e18)
    pd[n] = -1;
  cout << pd[n] << endl;
}
