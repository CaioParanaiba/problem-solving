#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
  int n, q;
  int case_num = 1;

  while (cin >> n >> q && (n != 0 || q != 0)) {
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    sort(all(a));

    cout << "CASE# " << case_num++ << ":" << endl;

    while (q--) {
      int x;
      cin >> x;

      auto it = lower_bound(all(a), x);

      if (it != a.end() && *it == x) {
        int pos = (it - a.begin()) + 1;
        cout << x << " found at " << pos << endl;
      } else {
        cout << x << " not found" << endl;
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
