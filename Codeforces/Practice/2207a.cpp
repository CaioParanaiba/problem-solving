#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
  int n;
  cin >> n;
  string m;
  cin >> m;

  int n1 = 0;
  for (int i = 0; i < n; i++) {
    if (m[i] == '1')
      n1++;
  }

  int max = 0, min = 0;
  for (int i = 1; i < n - 1; i++) {
    if (m[i - 1] == m[i + 1] && m[i - 1] == '1') {

      if (m[i] == '0') {
      }
    }
  }

  cout << n1 + min << ' ' << n1 + max << endl;
}

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
