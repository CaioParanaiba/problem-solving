#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  vector<int> c(m);

  for (int i = 0; i < m; i++) {
    int C;
    cin >> C;
    c[i] = C;
  }

  vector<int> a(m, 0);
  for (int i = 0; i < n; i++) {
    int A, B;
    cin >> A >> B;

    a[A - 1] += B;
  }

  int soma = 0;
  for (int i = 0; i < m; i++) {
    // cout << a[i] << '\t' << c[i] << endl;
    if (a[i] < c[i])
      soma += a[i];
    else
      soma += c[i];
  }

  cout << soma << endl;
}
