#include <bits/stdc++.h>
#include <vector>
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
  int n;
  while (cin >> n) {
    vector<int> a;
    while (n != -999999) {
      a.push_back(n);
      cin >> n;
    }

    int prod = 1;
    int ans = -99999;
    int s = a.size();
    for (int i = 0; i < s; i++) {
      prod *= a[i];
      ans = max(ans, prod);

      if ()
        prod = 1;
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
