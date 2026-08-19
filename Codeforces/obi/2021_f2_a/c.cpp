#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  vector<int> conf(n, 0);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    conf[x] |= 1LL << y;
    conf[y] |= 1LL << x;
  }

  int total = 1 << n;
  int ans = 0;
  for (int i = 1; i < total; i++) {

    bool foi = true;
    for (int j = 0; j < n && foi; j++) {
      if ((i & (1 << j)) && (conf[j] & i))
        foi = false;
    }
    if (foi)
      ans++;
  }
  cout << ans << endl;
}
