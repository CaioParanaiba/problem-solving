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

  string s[2];
  cin >> s[0] >> s[1];

  vector<int> pd(n + 1, 1e9);
  pd[0] = 0;

  for (int i = 1; i <= n; i++) {
    int custov = (s[0][i - 1] != s[1][i - 1] ? 1 : 0);
    pd[i] = min(pd[i], pd[i - 1] + custov);

    if (i >= 2) {
      int custoh = (s[0][i - 2] != s[0][i - 1] ? 1 : 0) +
                   (s[1][i - 2] != s[1][i - 1] ? 1 : 0);
      pd[i] = min(pd[i], pd[i - 2] + custoh);
    }
  }

  cout << pd[n] << endl;
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
