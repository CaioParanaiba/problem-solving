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

  vi a(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  bool possivel = true;

  for (int i = 1; i <= n; i++) {
    int pi = i;
    while (pi % 2 == 0)
      pi /= 2;
    int pa = a[i];
    while (pa % 2 == 0)
      pa /= 2;

    if (pi != pa)
      possivel = 0;
  }

  cout << (possivel ? "YES\n" : "NO\n");
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
