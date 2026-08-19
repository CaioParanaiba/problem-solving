#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n;
  cin >> n;

  vector<int> existe(10000001, 0);

  int maior = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    existe[x] = 1;
    maior = max(maior, x);
  }

  int ans = 0;
  for (int d = 1; d <= maior; d++) {
    if (existe[d])
      continue;
    int g = 0;
    for (int j = 2 * d; j <= maior; j += d) {
      if (existe[j]) {
        int k = j / d;
        g = gcd(k, g);
        if (g == 1)
          break;
      }
    }
    if (g == 1) {
      existe[d] = 1;
      ans++;
    }
  }

  cout << ans << endl;
}
