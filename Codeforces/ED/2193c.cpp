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

  vi a(n);
  vi b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++)
    if (a[i] < b[i])
      a[i] = b[i];

  vi pref(n + 1);
  pref[n] = 0;

  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1])
      a[i] = a[i + 1];
    pref[i + 1] = pref[i + 2] + a[i + 1];
  }
  pref[0] = pref[1] + a[0];

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    int sum = pref[l - 1] - pref[r];

    cout << sum << (i < q - 1 ? ' ' : '\n');
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
