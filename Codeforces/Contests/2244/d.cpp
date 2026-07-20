#include <bits/stdc++.h>
#include <vector>
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
  int n, m;

  cin >> n >> m;

  vector<int> a(n), b(m);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  sort(all(b));

  int sum = 0;
  int ans = 0;
  int bb = 0;

  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (bb < m && b[bb] - 1 == i) {
      ans += abs(sum);
      bb++;
      sum = 0;
    }
  }

  ans += sum;

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
