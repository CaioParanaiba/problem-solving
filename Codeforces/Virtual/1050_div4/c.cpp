#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sp " "

signed main() {

  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n, h;
    cin >> n >> h;
    int h0 = 0, p0 = 0;
    int pt = 0;
    for (int i = 0; i < n; i++) {
      int ht, p;
      cin >> ht >> p;

      // cout << ht << sp << h0 << sp << p << sp << p0 << endl;
      ;

      int hat = ht - h0;
      if (p != p0 && hat % 2 != 0) {
        pt += hat;
      } else
        pt += hat - 1;

      h0 = ht;
      p0 = p;
    }
    if (h0 != h)
      pt += h - h0;

    cout << pt << endl;
  }
}
