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
  int n, k;
  cin >> n >> k;

  vi a(n);

  int x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int p;
  cin >> p;
  x = a[p - 1];

  vi v(n);
  for (int i = 0; i < n; i++) {
    v[i] = (a[i] != x) ? 1 : 0;
  }

  int qtdL = (v[0] != 0) ? 1 : 0;
  for (int i = 0; i < p - 1; i++) {
    qtdL += (v[i] != v[i + 1]) ? 1 : 0;
  }

  int qtdR = 0;
  for (int i = p - 1; i < n - 1; i++) {
    qtdR += (v[i] != v[i + 1]) ? 1 : 0;
  }

  int ans = max(qtdL, qtdR);

  if (ans % 2 == 1)
    ans++;

  cout << ans << endl;
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
