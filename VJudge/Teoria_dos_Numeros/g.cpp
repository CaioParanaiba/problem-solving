#include <bits/stdc++.h>

using namespace std;

#define int long long

int MAXN = 1e6 + 5;

void solve() {
  int n;
  cin >> n;

  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    for (int k = 2; k * k <= x; k++) {
      while (x % k == 0) {
        mp[k]++;
        x /= k;
      }
    }

    if (x > 1)
      mp[x]++;
  }

  bool possivel = true;
  for (auto a : mp) {
    if (a.second % n != 0) {
      possivel = false;
      break;
    }
  }

  cout << (possivel ? "YES\n" : "NO\n");
}

signed main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
