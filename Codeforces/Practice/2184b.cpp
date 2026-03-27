#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long

// const int MOD = 1e9 + 7;
// const int INF = 1e18;

void solve() {
  int s, k, m;
  cin >> s >> k >> m;

  int tempo = 0;
  if (s > k)
    s = k;
  if (k <= m)
    // cout << s << '-' << max(m - (m / k) * k, 0) << endl;
    tempo = max(s - max(m % k, 0), 0);

  cout << tempo << endl;
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
