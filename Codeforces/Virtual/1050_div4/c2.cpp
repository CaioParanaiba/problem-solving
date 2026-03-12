#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;

    int h0 = 0, p0 = 0, pontos = 0;
    for (int j = 0; j < n; j++) {
      int hf, pf;
      cin >> hf >> pf;

      int hat = hf - h0;
      if ((p0 != pf) != (hat % 2))
        pontos--;
      pontos += hat;

      h0 = hf;
      p0 = pf;
    }
    if (h0 != m)
      pontos += m - h0;

    cout << pontos << endl;
  }
}
