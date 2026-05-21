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
  string s;
  cin >> s;

  int d = -1;

  int d0 = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'R') {
      d = max(d, i - d0);
      d0 = i;
    }
  }

  int i = s.size();
  d = max(d, i - d0);

  cout << d << endl;
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
