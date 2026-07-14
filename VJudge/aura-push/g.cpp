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

  vector<int> v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  int r = n;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] >= (n - 1 - i))
      r = i;
    else
      break;
  }

  int l = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] >= i)
      l = i;
    else
      break;
  }

  cout << (l >= r ? "YES\n" : "NO\n");
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
