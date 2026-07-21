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

  vector<int> p(n + 1), sz(n + 1, 1);

  iota(all(p), 0);

  vector<tuple<int, int, int>> dis;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dis.push_back({c, a, b});
  }

  sort(all(dis));

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

    if (sz[a] < sz[b])
      swap(a, b);

    p[b] = a;
    sz[a] += sz[b];
  };

  auto same = [&](int a, int b) -> bool {
    return find(find, a) == find(find, b);
  };

  int ans = 0, arestas = 0;

  for (auto [c, a, b] : dis) {
    if (same(a, b))
      continue;
    ans += c;
    arestas++;
    uni(a, b);
  }

  if (arestas < n - 1)
    cout << "IMPOSSIBLE" << endl;
  else
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
