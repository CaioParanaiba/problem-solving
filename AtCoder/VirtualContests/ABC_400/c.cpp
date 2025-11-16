#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  ll n;
  cin >> n;

  ll num = 0;
  ll lim = sqrt(n);
  for (ll b = 1; b <= lim; b++) {
    if (b % 2 != 0) {
      ll x = 2 * b * b;
      while (x <= n) {
        num++;
        x = x * 2;
      }
    }
  }

  cout << num << '\n';

  return 0;
}
