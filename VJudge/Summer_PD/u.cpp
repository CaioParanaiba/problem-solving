#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

constexpr int MOD = 1e9 + 7;

signed main() {

  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  array<int, 100> coins;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  for (int i = n; i < 100; i++)
    coins[i] = MOD;
  sort(coins.begin(), coins.end());

  array<int, (size_t)(1e6) + 1> pd = {0};
  pd[0] = 1;

  int moeda1 = coins[0];
  int j, cnt = 0;
  for (int i = moeda1; i <= x; i++) {
    for (j = 0; j < n; j++) {
      if (i < coins[j])
        break;
      pd[i] = (pd[i - coins[j]] + pd[i]) % MOD;
    }
  }

  cout << pd[x] << endl;
}
