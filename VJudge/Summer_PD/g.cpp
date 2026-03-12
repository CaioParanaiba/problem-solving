#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int INF = 1e18;

signed main() {

  int n;
  cin >> n;

  vector<int> pd(2);

  pd[0] = 0;
  pd[1] = -INF;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    if (x == 1)
      pd[1] = max(pd[0] + y, pd[1]);
    else
      pd[0] = max({pd[0], pd[1] + y, pd[0] + y});
  }

  cout << max(pd[0], pd[1]) << endl;
}
