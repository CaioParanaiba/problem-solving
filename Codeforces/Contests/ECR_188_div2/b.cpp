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
  for (int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;

    int r = 1;
    int maior;
    cin >> maior;
    for (int i = 1; i < n; i++) {
      int a;
      cin >> a;
      if (a >= maior) {
        // cout << a << ' ' << maior << endl;
        r++;
        maior = a;
      }
    }
    cout << r << endl;
  }
}
