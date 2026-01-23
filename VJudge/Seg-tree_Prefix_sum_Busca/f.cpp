#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n, q, c = 1;
  cin >> n >> q;
  while (n != 0 || q != 0) {
    cout << "CASE# " << c << ':' << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      int vi;
      cin >> vi;
      v[i] = vi;
    }

    sort(begin(v), end(v));

    for (int i = 0; i < q; i++) {
      int qi;
      cin >> qi;

      auto ii = lower_bound(begin(v), end(v), qi);

      cout << qi << ' ';
      if (*ii != qi)
        cout << "not found\n";
      else
        cout << "found at " << ii - begin(v) + 1 << endl;
    }
    c++;
    cin >> n >> q;
  }
}
