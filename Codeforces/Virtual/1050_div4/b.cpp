#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int t;
  cin >> t;

  for (int tt = 0; tt < t; tt++) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int total = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a < y)
        total++;
    }
    for (int i = 0; i < m; i++) {
      int b;
      cin >> b;
      if (b < x)
        total++;
    }

    cout << total << endl;
  }
}
