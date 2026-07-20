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
  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }

  sort(all(a));

  int i = 0, j = n - 1;

  int sum = -1;
  while (i < j) {
    sum = a[i].first + a[j].first;

    if (sum == x) {
      cout << a[i].second << ' ' << a[j].second << endl;
      return;
    }
    if (sum < x)
      i++;
    else
      j--;
  }

  cout << "IMPOSSIBLE\n";
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
