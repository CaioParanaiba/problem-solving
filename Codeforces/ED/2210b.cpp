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

  vector<bool> check(n, 0);
  vi p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  int total = 0;
  for (int i = 0; i < n && !check[i]; i++) {
    if (i >= p[i] - 1) {
      total++;
      check[p[i] - 1] = 1;
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
