#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n, m;
  cin >> n >> m;

  vector<int> h(n);
  vector<int> sum_c(n);
  vector<int> sum_d(n);

  for (int i = 0; i < n; i++) {
    int hi;
    cin >> hi;
    h[i] = hi;
  }

  sum_c[0] = 0;
  sum_d[n - 1] = 0;
  for (int i = 1; i < n; i++) {
    if (h[i] < h[i - 1]) {
      sum_c[i] = sum_c[i - 1] + h[i - 1] - h[i];
    } else {
      sum_c[i] = sum_c[i - 1];
    }

    if (h[n - 1 - i] < h[n - i]) {
      sum_d[n - 1 - i] = sum_d[n - i] + (h[n - i] - h[n - 1 - i]);
    } else {
      sum_d[n - 1 - i] = sum_d[n - i];
    }
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    x--, y--;

    int damage = (x < y) ? sum_c[y] - sum_c[x] : sum_d[y] - sum_d[x];

    cout << damage << endl;
  }
}
