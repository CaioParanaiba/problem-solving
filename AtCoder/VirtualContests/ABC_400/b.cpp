#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n, m;
  cin >> n >> m;

  ll lim = pow(10, 9);
  ll x = 1;
  for (int i = 1; i <= m; i++) {
    x += pow(n, i);
    if (x > lim) {
      break;
    }
  }

  if (x <= lim)
    cout << x << '\n';
  else
    cout << "inf\n";

  return 0;
}
