#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int dif(int x, int y) {
  if (x > y)
    return x - y;
  else
    return y - x;
}

signed main() {

  int n;
  cin >> n;

  vector<int> v(n);
  vector<int> c(n);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    v[i] = a;
    if (i == 0)
      c[0] = 0;
    else if (i == 1) {
      c[1] = dif(v[1], v[0]);
    } else {
      int custo1 = c[i - 1] + dif(v[i], v[i - 1]);
      int custo2 = c[i - 2] + dif(v[i], v[i - 2]);
      c[i] = (custo1 <= custo2) ? custo1 : custo2;
    }
  }

  cout << c[n - 1] << endl;
}
