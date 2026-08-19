#include <bits/stdc++.h>

using namespace std;

#define int long long

int MAXN = 1e6 + 5;

signed main() {
  int n;
  cin >> n;

  int maxn = n;
  int ans = 0;
  for (int i = 2; i * i <= maxn; i++) {
    if (n % i == 0) {
      int a = 0;
      while (n % i == 0) {
        a++;
        n /= i;
      }
      int k = 0;
      while ((k + 1) * (k + 2) / 2 <= a) {
        ans++;
        k++;
      }
    }
  }

  if (n > 1)
    ans++;

  cout << ans << endl;
}
