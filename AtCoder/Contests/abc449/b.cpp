#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w, q;
  cin >> h >> w >> q;

  int eat = 0;
  for (int i = 0; i < q; i++) {
    int t, qt;
    cin >> t >> qt;

    if (t == 2) {
      eat = qt * h;
      w -= qt;
    } else {
      eat = qt * w;
      h -= qt;
    }
    cout << eat << endl;
    eat = 0;
  }
}
