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

int buildseg(vi &a, vi &seg, int p, int l, int r) {
  if (l == r)
    return seg[p] = a[l];

  int m = (l + r) >> 1;
  return seg[p] = max(buildseg(a, seg, p * 2, m, r),
                      buildseg(a, seg, p * 2 + 1, l, m + 1));
}

void solve() {
  int n;
  cin >> n;

  vi a(n);
  vi seg(4 * n);

  for (int i = 0; i < n; i++)
    cin >> a[i];
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
