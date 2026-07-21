#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
  int n;
  cin >> n;

  vector<int> p(n + 1);
  vector<int> sz(n + 1, 1);
  iota(p.begin(), p.end(), 0);

  auto Find = [&](auto &self, int a) -> int {
    if (p[a] == a)
      return a;
    return p[a] = self(self, p[a]);
  };

  auto uni = [&](int a, int b) -> void {
    a = Find(Find, a);
    b = Find(Find, b);
    if (a == b)
      return;

    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
  };

  auto same = [&](int a, int b) -> bool {
    return Find(Find, a) == Find(Find, b);
  };

  vector<pair<int, int>> build, destroy;

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (same(a, b))
      destroy.push_back({a, b});
    else {
      uni(a, b);
    }
  }

  for (int i = 2; i <= n; i++) {
    if (!same(1, p[i])) {
      build.push_back({1, i});
      uni(1, i);
    }
  }

  int t = build.size();
  cout << t << endl;
  for (int i = 0; i < t; i++) {
    cout << destroy[i].first << ' ' << destroy[i].second << ' '
         << build[i].first << ' ' << build[i].second << endl;
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
