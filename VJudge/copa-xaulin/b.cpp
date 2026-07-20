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

  vector<vector<int>> mat(1005, vector<int>(1005, 0));

  while (n--) {
    int i, j;
    cin >> i >> j;
    mat[i][j] += i * j;
  }

  vector<vector<int>> pref(1005, vector<int>(1005, 0));

  for (int i = 1; i < 1005; i++) {
    for (int j = 1; j < 1005; j++)
      pref[i][j] =
          mat[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
  }

  while (q--) {
    int hs, ws, hb, wb;
    cin >> hs >> ws >> hb >> wb;

    cout << pref[hb - 1][wb - 1] - pref[hb - 1][ws] - pref[hs][wb - 1] +
                pref[hs][ws]
         << endl;
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
