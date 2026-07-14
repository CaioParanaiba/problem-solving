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

  int m1 = -1, m2 = -1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] > m1) {

      m2 = m1;
      m1 = v[i];
    } else if (v[i] > m2)
      m2 = v[i];
  }

  for (int i = 0; i < n; i++) {
    if (v[i] == m1)
      v[i] -= m2;
    else
      v[i] -= m1;
  }

  for (int i = 0; i < n; i++)
    cout << v[i] << (i < n - 1 ? " " : "\n");
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
