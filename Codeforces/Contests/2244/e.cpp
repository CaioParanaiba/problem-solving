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
  cin >> n >> q;

  string s;
  cin >> s;

  vector<int> pref(n + 1, 0);
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + (s[i - 1] == s[i] ? 1 : 0);
  }

  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    int zuado = (l == r) ? 0 : pref[r - 1] - pref[l - 1];
    int ans = (zuado + 1) / 2;

    cout << (ans <= k ? "YES\n" : "NO\n");
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
