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

  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(all(a));

  int minimo = -1e18;
  for (int i = 0; i < n - 1; i += 2) {
    minimo = max(minimo, abs(a[i] - a[i + 1]));
  }

  cout << minimo << endl;
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
