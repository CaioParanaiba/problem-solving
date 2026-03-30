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

void up_sec(vector<pair<int, int>> &seg, int p) {
  if (seg[p].first == seg[p * 2].first)
    seg[p].second += seg[p * 2].second;
  if (seg[p].first == seg[p * 2 + 1].first)
    seg[p].second += seg[p * 2 + 1].second;
}

pair<int, int> combina(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first)
    return min(a, b);
  return {a.first, a.second + b.second};
}

void build(vi &v, vector<pair<int, int>> &seg, int p, int l, int r) {
  if (r == l) {
    seg[p] = {v[r], 1};
    return;
  }

  int m = (r + l) >> 1;
  build(v, seg, p * 2, l, m);
  build(v, seg, p * 2 + 1, m + 1, r);

  seg[p] = combina(seg[p * 2], seg[p * 2 + 1]);
}

void up(vi &v, vector<pair<int, int>> &seg, int p, int l, int r, int i, int x) {
  if (l > i || r < i)
    return;
  if (l == r) {
    seg[p] = {x, 1};
    return;
  }

  int m = (l + r) >> 1;
  up(v, seg, p * 2, l, m, i, x);
  up(v, seg, p * 2 + 1, m + 1, r, i, x);

  seg[p] = combina(seg[p * 2], seg[p * 2 + 1]);
}

pair<int, int> minimo(vi &v, vector<pair<int, int>> &seg, int p, int l, int r,
                      int i, int j) {
  if (l > j || r < i)
    return {INF, 0};
  if (l >= i && r <= j)
    return seg[p];

  int m = (r + l) >> 1;
  pair<int, int> esq, dir;
  esq = minimo(v, seg, p * 2, l, m, i, j);
  dir = minimo(v, seg, p * 2 + 1, m + 1, r, i, j);
  return combina(esq, dir);
}

void solve() {
  int n, m;
  cin >> n >> m;

  vi v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<pair<int, int>> seg(4 * n);

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
      pair<int, int> mini = minimo(v, seg, 1, 0, n - 1, l, r - 1);
      cout << mini.first << ' ' << mini.second << endl;
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
