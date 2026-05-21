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
const int mod = 998244353;

int contar_resto(int k, int resto) {
  if (k < 0)
    return 0;
  int res = k / 4;
  if (k % 4 >= resto)
    res++;
  return res;
}

int contar_zero(int k) {
  if (k < 0)
    return 0;
  return 1 + contar_resto(k, 3);
}

int contar_n1(int k) {
  if (k < 0)
    return 0;
  return contar_resto(k, 1);
}

void solve() {
  int n, x;
  cin >> n >> x;

  int zerosl = contar_zero(x - 1);
  int n1l = contar_n1(x - 1);

  int zerosr = contar_zero(n) - contar_zero(x - 1);
  int n1r = contar_n1(n) - contar_n1(x - 1);

  int total0 = ((zerosl % mod) * (zerosr % mod)) % mod;
  int total1 = ((n1l % mod) * (n1r % mod)) % mod;
  int total = (total0 + total1) % mod;

  cout << total << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
