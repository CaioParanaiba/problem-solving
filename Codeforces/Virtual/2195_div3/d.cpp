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
  int n;
  cin >> n;

  vi f(n);
  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> f[i];

  int soma_internos1 = 0;
  int soma_internosn = 0;
  for (int i = 1; i < n - 1; i++) {
    a[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
    soma_internos1 += a[i] * i;
    soma_internosn += a[i] * (n - 1 - i);
  }

  a[n - 1] = f[0] - soma_internos1;
  a[0] = f[n - 1] - soma_internosn;

  a[n - 1] = a[n - 1] / (n - 1);
  a[0] = a[0] / (n - 1);

  for (int i = 0; i < n; i++)
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
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
