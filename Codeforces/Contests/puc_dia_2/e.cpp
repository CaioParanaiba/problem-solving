#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n, k;
  cin >> n >> k;

  int m = n / 2;

  if (m == 0) {
    if (k == 0)
      cout << 1 << endl;
    else
      cout << -1 << endl;

    return 0;
  }
  if (m > k) {
    cout << -1 << endl;
    return 0;
  }

  int g = k - (m - 1);
  vector<int> ans;
  ans.push_back(g);
  ans.push_back(g * 2);

  int base = 1;
  for (int i = 0; i < m - 1; i++) {
    while (base == g || base == 2 * g || base + 1 == g || base + 1 == 2 * g)
      base++;
    ans.push_back(base);
    ans.push_back(base + 1);
    base += 2;
  }

  if (n & 1) {
    while (base == g || base == 2 * g || base + 1 == g || base + 1 == 2 * g)
      base++;
    ans.push_back(base);
  }

  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
}
