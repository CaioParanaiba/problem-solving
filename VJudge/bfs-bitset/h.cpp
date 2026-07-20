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
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];

  vector<bitset<4005>> prefa(n + 1), prefb(m + 1);

  for (int i = 1; i <= n; i++) {
    prefa[i] = prefa[i - 1];
    prefa[i].flip(a[i]);
  }

  for (int i = 1; i <= m; i++) {
    prefb[i] = prefb[i - 1];
    prefb[i].flip(b[i]);
  }

  while (q--) {
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;

    bitset<4005> bita = prefa[ra] ^ prefa[la - 1];
    bitset<4005> bitb = prefb[rb] ^ prefb[lb - 1];

    cout << (bita ^ bitb).count() << endl;
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
