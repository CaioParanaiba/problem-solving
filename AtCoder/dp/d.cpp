#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

signed main() {
  int n, w;
  cin >> n >> w;

  vector<int> pd(w + 1, 0);

  for (int i = 0; i < n; i++) {
    int W, v;
    cin >> W >> v;
    for (int j = w; j >= 0; j--)
      pd[j] = (j < W) ? pd[j] : max(pd[j], pd[j - W] + v);
  }

  cout << pd[w] << endl;
}
