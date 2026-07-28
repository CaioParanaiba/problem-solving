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

  vector<pii> soldados(n);

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    soldados[i] = {a, b};
  }

  sort(all(soldados),
       [](pii a, pii b) { return a.first - a.second > b.first - b.second; });

  int sum = 0, atual = 0;
  for (auto [a, b] : soldados) {
    if (atual < a) {
      sum += a - atual;
      atual = a;
    }
    atual -= b;
  }

  cout << sum << endl;
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
