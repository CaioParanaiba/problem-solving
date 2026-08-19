#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> p, sz;
  vector<pair<int, int>> mm;
  int comps;
  DSU(int n) : p(n + 1), sz(n + 1, 1), mm(n + 1), comps(n) {
    for (int i = 0; i <= n; i++) {
      p[i] = i;
      mm[i] = {i, i};
    }
  }

  int find(int a) {
    if (p[a] == a)
      return a;
    return p[a] = find(p[a]);
  };

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    mm[a] = {max(mm[a].first, mm[b].first), min(mm[a].second, mm[b].second)};
    p[b] = a;
    sz[a] += sz[b];
    comps--;
    return true;
  };

  bool same(int a, int b) { return find(a) == find(b); };
  int size(int a) { return sz[find(a)]; };
};

int main() {
  int n, k;
  cin >> n >> k;
  DSU dsu(n);

  while (k--) {
    string s;
    int a, b;
    cin >> s;

    if (s == "union") {
      cin >> a >> b;
      dsu.unite(a, b);
    } else {
      cin >> a;
      a = dsu.find(a);
      cout << dsu.mm[a].second << ' ' << dsu.mm[a].first << ' ' << dsu.size(a)
           << endl;
    }
  }
}
