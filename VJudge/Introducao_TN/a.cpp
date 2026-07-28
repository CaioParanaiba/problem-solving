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

  vector<int> p(1e6 + 5, 0);

  for (int i = 2; i <= 1e6; i++) {
    if (p[i] != 0)
      continue;
    p[i] = i;
    for (int j = i + i; j <= 1e6; j += i) {
      if (!p[j])
        p[j] = i;
    }
  }

  while (n--) {
    int x;
    cin >> x;

    int ans = 1;
    while (x > 1) {
      int primo = p[x];
      int cnt = 0;
      while (x % primo == 0) {
        cnt++;
        x /= primo;
      }
      ans *= (cnt + 1);
    }
    cout << ans << endl;
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
