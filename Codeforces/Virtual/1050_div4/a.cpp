#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int x, n;
    cin >> x >> n;
    int soma = 0;

    for (int j = 0; j < n; j++) {
      soma += x;
      x = -x;
    }

    cout << soma << endl;
  }
}
