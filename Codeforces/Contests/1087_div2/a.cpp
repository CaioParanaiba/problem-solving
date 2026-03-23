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
    int n, c, k;
    cin >> n >> c >> k;

    vector<int> m(n);
    for (int i = 0; i < n; i++) {
      cin >> m[i];
    }

    sort(m.begin(), m.end());
    // int i = 0;
    // cout <
    for (int i = 0; i < n; i++) {
      if (c >= m[i]) {
        int usar = min(k, c - m[i]);
        m[i] += usar;
        k -= usar;
        c += m[i];
      } else {
        break;
      }
    }
    cout << c << endl;
  }
}
