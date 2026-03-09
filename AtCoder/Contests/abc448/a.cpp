#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a < x) {
      x = a;
      cout << 1 << endl;
    } else
      cout << 0 << endl;
  }
}
