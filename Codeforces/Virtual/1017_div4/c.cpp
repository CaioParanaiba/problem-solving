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

  vi p(2 * n);
  vector<bool> vis(2 * n + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      p[i + j + 1] = x;
      vis[x] = 1;
    }
  }

  for (int i = 1; i <= 2 * n; i++) {
    if (!vis[i]) {
      p[0] = i;
      break;
    }
  }

  for (int i = 0; i < 2 * n; i++) {
    cout << p[i] << (i != 2 * n - 1 ? " " : "\n");
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
