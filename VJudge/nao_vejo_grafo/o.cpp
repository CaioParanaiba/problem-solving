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
  int n, x, y;
  cin >> n >> x >> y;

  int g = gcd(x, y);

  bool ans = true;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;

    if (abs(a - i) % g != 0)
      ans = false;
  }

  cout << (ans ? "YES\n" : "NO\n");
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
