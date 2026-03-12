#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n, W;
  cin >> n >> W;
  W++;

  vector<int> pd(W, 0);

  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;

    for (int j = W - 1; j > 0; j--) {
      if (w <= j)
        pd[j] = max(pd[j], pd[j - w] + v);
    }
  }

  cout << pd[W - 1] << endl;
}
