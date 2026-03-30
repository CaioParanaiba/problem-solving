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

void build(vi &v, vi &seg, int p, int l, int r) {
  if (r == l) {
    seg[p] = v[l];
    return;
  }
  int m = (r + l) >> 1;
  build(v, seg, p * 2, l, m);
  build(v, seg, p * 2 + 1, m + 1, r);
  seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}

void up(vi &v, vi &seg, int p, int l, int r, int i, int x) {
  if (l == r) {
    seg[p] = x;
    return;
  }

  int m = (l + r) >> 1;
  if (i <= m)
    up(v, seg, p * 2, l, m, i, x);
  else
    up(v, seg, p * 2 + 1, m + 1, r, i, x);
  seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
}

int minimo(vi &v, vi &seg, int p, int l, int r, int i, int j) {
  if (l > j || r < i)
    return INF;
  if (l >= i && r <= j)
    return seg[p];

  int m = (l + r) >> 1;
  return min(minimo(v, seg, p * 2, l, m, i, j),
             minimo(v, seg, p * 2 + 1, m + 1, r, i, j));
}

void solve() {
  int n, m;
  cin >> n >> m;

  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vi seg(4 * n);

  build(v, seg, 1, 0, n - 1);

  for (int ii = 0; ii < m; ii++) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      up(v, seg, 1, 0, n - 1, i, x);
    } else if (type == 2) {
      int l, r;
      cin >> l >> r;
      cout << minimo(v, seg, 1, 0, n - 1, l, r - 1) << endl;
    }
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
