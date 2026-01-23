#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int t;
  cin >> t;

  for (int ti = 0; ti < t; ti++) {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    vector<int> sum(n + 1);
    sum[0] = 0;

    for (int i = 0; i < n; i++) {
      int ni;
      cin >> ni;
      v[i] = ni;
      sum[i + 1] = sum[i] + ni;
    }

    for (int i = 0; i < q; i++) {
      int l, r, k;
      cin >> l >> r >> k;

      int total = sum[n] - (sum[r] - sum[l - 1]) + k * (r + 1 - l);
      if (total % 2 == 0)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
}
