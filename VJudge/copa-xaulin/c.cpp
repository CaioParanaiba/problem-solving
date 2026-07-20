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

  vector<int> v(n), freq(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i - 1];
    freq[i] = freq[i - 1] + v[i - 1];
  }

  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;

    int nova = k * (r - l + 1);
    int antiga = freq[r] - freq[l - 1];

    cout << ((freq[n] - antiga + nova) & 1 ? "YES\n" : "NO\n");
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
