#include <bits/stdc++.h>

using namespace std;

#define int long long

int MOD = 1e9 + 7;

int expofast(int base, int exp) {
  int resultado = 1;
  base %= MOD;
  while (exp > 0) {
    if (exp & 1)
      resultado = (resultado * base) % MOD;
    base = (base * base) % MOD;
    exp /= 2;
  }

  return resultado;
}

int inv(int y) { return expofast(y, MOD - 2); }

signed main() {
  int a, b, n, x;
  cin >> a >> b >> n >> x;

  a %= MOD;
  b %= MOD;
  x %= MOD;

  int A = expofast(a, n);

  int g;
  if (a == 1)
    g = (x + (b * (n % MOD) % MOD) % MOD) % MOD;
  else {
    int termo1 = (A * x) % MOD;
    int numerador = (b * (A - 1 + MOD) % MOD) % MOD;
    int denominador = (inv((a - 1 + MOD) % MOD)) % MOD;
    int termo2 = (numerador * denominador) % MOD;
    g = (termo1 + termo2) % MOD;
  }
  cout << g << endl;
}
