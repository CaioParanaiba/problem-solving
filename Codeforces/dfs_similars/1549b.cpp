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

  string a, b;
  cin >> a >> b;

  int total = 0;

  for (int i = 0; i < n; i++) {
    if (b[i] == '0')
      continue;
    if (a[i] == '0') {
      total++;
      a[i] = 'x';
    } else {
      if (i > 0 && a[i - 1] == '1') {
        total++;
        a[i - 1] = 'x';
      } else if (i < n - 1 && a[i + 1] == '1') {
        total++;
        a[i + 1] = 'x';
      }
    }
  }

  cout << total << endl;
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
