#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n / 3 >= 2)
      cout << 0 << endl;
    else if (n / 3 == 0)
      cout << 2 << endl;
    else
      cout << 1 << endl;
  }
}
