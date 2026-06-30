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
  string s;
  cin >> n >> s;

  int inversoes = 0;
  vector<int> n0d(n + 1, 0), n1e(n + 1, 0);

  int uns = 0;
  for (int i = 0; i < n; i++) {
    n1e[i] = uns;
    if (s[i] == '1')
      uns++;
  }

  int zeros = 0;
  for (int i = n - 1; i >= 0; i--) {
    n0d[i] = zeros;
    if (s[i] == '0')
      zeros++;
  }

  bool inversao_impar = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      inversoes += n0d[i];
      if (n0d[i] & 1)
        inversao_impar = true;
    } else {
      inversoes += n1e[i];
      if (n1e[i] & 1)
        inversao_impar = true;
    }
  }

  cout << ((inversoes & 1 || inversao_impar) ? "Alice" : "Bob") << endl;
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
