#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;
    n = n * 2;

    int n1 = 0, n0 = 0;
    // cout << "testessss" << endl;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      // cout << "VALOR A " << a << endl;
      if (a == 1)
        n1++;
      else
        n0++;
    }

    // cout << "n1 = " << n1 << " n0 = " << n0 << endl;
    int min = n1 % 2;
    int max = (n0 >= n1) ? n1 : n0;

    cout << min << ' ' << max << endl;
  }
}
