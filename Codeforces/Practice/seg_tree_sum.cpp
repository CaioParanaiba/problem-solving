#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

int build(vector<int> &v, vector<int> &seg, int p, int l, int r) {
  if (l == r) {
    return seg[p] = v[l];
  }

  int m = (l + r) >> 1;

  return seg[p] =
             build(v, seg, p * 2, l, m) + build(v, seg, p * 2 + 1, m + 1, r);
}

int query(vector<int> &v, vector<int> &seg, int p, int l, int r, int i, int j) {
  if (l > j || r < i)
    return 0;
  if (i <= l && r <= j)
    return seg[p];

  int m = (l + r) >> 1;

  return query(v, seg, p * 2, l, m, i, j) +
         query(v, seg, p * 2 + 1, m + 1, r, i, j);
}

int up(vector<int> &v, vector<int> &seg, int p, int l, int r, int i, int x) {
  if (l > i || r < i)
    return seg[p];
  if (l == r)
    return seg[p] = x;

  int m = (r + l) >> 1;

  return seg[p] = up(v, seg, p * 2, l, m, i, x) +
                  up(v, seg, p * 2 + 1, m + 1, r, i, x);
}

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<int> seg(4 * n);

  int soma = build(v, seg, 1, 0, n - 1);

  for (int i = 0; i < m; i++) {
    int t, ii, j;
    cin >> t >> ii >> j;

    if (t == 2)
      cout << query(v, seg, 1, 0, n - 1, ii, j - 1) << endl;
    else if (t == 1) {
      soma = up(v, seg, 1, 0, n - 1, ii, j);
    }
  }
}
