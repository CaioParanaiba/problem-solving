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
  string s;
  cin >> s;

  int erros = 0;
  for (int i = 0; i < (int)s.size() - 1; i++) {
    if (s[i] == s[i + 1])
      erros++;
  }

  cout << (erros >= 3 ? "NO\n" : "YES\n");
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
