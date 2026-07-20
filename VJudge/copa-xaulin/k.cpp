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
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  vector<int> u = v;

  sort(all(u));

  vector<int> prefv(n + 1, 0), prefu(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefv[i] = prefv[i - 1] + v[i - 1];
    prefu[i] = prefu[i - 1] + u[i - 1];
  }

  int q;
  cin >> q;
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;

    if (t == 1)
      cout << prefv[r] - prefv[l - 1] << endl;
    else
      cout << prefu[r] - prefu[l - 1] << endl;
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
