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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int max_min = -INF;

  for (int i = 0; i < n - k + 1; i++) {
    int minimo = INF;
    vi janela(k);
    for (int j = i; j < i + k; j++) {

      minimo = min(a[j], minimo);
    }
    // cout << endl << minimo << endl;
    max_min = max(minimo, max_min);
  }

  cout << max_min << endl;
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
