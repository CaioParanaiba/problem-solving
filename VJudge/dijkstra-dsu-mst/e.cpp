#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
// #define sz(x) (int)(x).size()

using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;

  int nc = n;
  int maior = 1;

  vector<int> sz(n + 1, 1), p(n + 1);

  iota(p.begin(), p.end(), 0);

  auto find = [&](auto &self, int a) -> int {
    if (a == p[a])
      return a;
    return p[a] = self(self, p[a]);
  };

  auto uni = [&](int a, int b) -> void {
    a = find(find, a);
    b = find(find, b);

    if (a == b)
      return;

    if (sz[b] > sz[a])
      swap(a, b);

    p[b] = a;
    sz[a] += sz[b];
    nc--;
    maior = max(maior, sz[a]);
  };

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    uni(a, b);

    cout << nc << ' ' << maior << endl;
  }
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
