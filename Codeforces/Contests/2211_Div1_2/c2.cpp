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
  vi b(n);
  vector<map<int, int>> cadeia(k);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cadeia[i % k][a[i]]++;
  }

  bool possivel = true;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] != -1) {
      if (cadeia[i % k][b[i]] > 0)
        cadeia[i % k][b[i]]--;
      else
        possivel = false;
    }
  }

  cout << (possivel ? "YES" : "NO") << endl;
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
