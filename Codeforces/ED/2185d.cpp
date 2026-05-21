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
  int n, m, h;
  cin >> n >> m >> h;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = a[i].first;
  }

  vi b(n, 0);
  int parametro = -1;

  for (int i = 0; i < m; i++) {
    int q, x;
    cin >> q >> x;
    q--;

    if (parametro >= b[q])
      a[q].second = a[q].first;

    b[q] = i;

    if (parametro < b[q])
      a[q].second += x;

    if (a[q].second > h)
      parametro = i;
  }

  for (int i = 0; i < n; i++)
    cout << (parametro < b[i] ? a[i].second : a[i].first)
         << (i == n - 1 ? '\n' : ' ');
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
