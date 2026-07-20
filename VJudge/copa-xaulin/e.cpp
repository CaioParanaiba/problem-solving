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
  int n, t;
  cin >> n >> t;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int sum = 0;
  int ans = 0;

  queue<int> q;

  for (int i = 0; i < n; i++) {
    q.push(a[i]);
    sum += a[i];

    while (sum > t) {
      sum -= q.front();
      q.pop();
    }

    ans = max(ans, (int)q.size());
  }

  cout << ans << endl;
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
