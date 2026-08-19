#include <bits/stdc++.h>

using namespace std;

#define int long long

int MOD = 1e9 + 7;

signed main() {
  int n, m;
  cin >> n >> m;

  int M = min(n, m);
  int t = 0;

  for (int i = 1; i <= M;) {
    int v = n / i;
    int r = min(n / v, M);
    int contardokrl = r - i + 1;
    int AAAAA = (((i + r) % MOD) * (contardokrl % MOD) / 2) % MOD;

    int valordokrl = v % MOD;
    int sumadokrl = ((AAAAA % MOD) * valordokrl % MOD) % MOD;
    t = (t + sumadokrl) % MOD;
    i = r + 1;
  }

  int nm = ((n % MOD) * (m % MOD)) % MOD;
  cout << ((nm - t) % MOD + MOD) % MOD << endl;
}
