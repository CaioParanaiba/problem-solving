#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int MOD = 1e9 + 7;

signed main() {

  int n;
  cin >> n;

  int dados[6] = {1, 2, 3, 4, 5, 6};

  vector<int> pd(n + 1);

  pd[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (auto d : dados) {
      if (i - d >= 0) {
        pd[i] += pd[i - d];
        pd[i] %= MOD;
      }
    }
  }

  cout << pd[n] << endl;
}
