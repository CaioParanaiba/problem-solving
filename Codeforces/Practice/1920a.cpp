#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int inf = -1e18, sup = 1e18;

    vector<int> dif;
    for (int i = 0; i < n; i++) {
      int type, x;
      cin >> type >> x;
      if (type == 3)
        dif.push_back(x);
      else if (type == 1) {
        if (x > inf)
          inf = x;
      } else if (type == 2) {
        if (x < sup)
          sup = x;
      }

      // cout << "inf: " << inf << " sup: " << sup << endl;
    }

    // cout << endl << endl;
    int total = 0;

    if (inf <= sup) {
      total = sup - inf + 1;
      sort(dif.begin(), dif.end());
      for (int i = 0; i < dif.size(); i++) {
        if (dif[i] > sup)
          break;
        if (dif[i] >= inf)
          total--;
      }
    }

    cout << total << endl;
  }
}
