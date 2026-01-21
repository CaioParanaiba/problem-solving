#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n, m;
  cin >> n >> m;

  vector<int> h(n);
  vector<int> sum(n);

  for (int i = 0; i < n; i++) {
    int hi;
    cin >> hi;
    h[i] = hi;
  }

  sum[0] = 0;
  for (int i = 1; i < n; i++) {
    if (h[i] < h[i - 1])
      sum[i] = sum[i - 1] + h[i - 1] - h[i];
    else
      sum[i] = sum[i - 1];
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    x--, y--;

    int damage = sum[y] - sum[x];

    cout << damage << endl;
  }
}
