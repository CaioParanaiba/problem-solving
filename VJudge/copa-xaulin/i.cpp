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

  vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;

      v[i][j] = (c == '.') ? 0 : 1;
    }
  }

  vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pref[i][j] =
          v[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }

  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    cout << pref[y2][x2] - pref[y2][x1 - 1] - pref[y1 - 1][x2] +
                pref[y1 - 1][x1 - 1]
         << endl;
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
