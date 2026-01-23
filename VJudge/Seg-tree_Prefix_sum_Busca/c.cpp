#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define endl '\n'
#define int long long

int Achar(int l, int dinheiro, int n, vector<int> &v) {
  auto ii = lower_bound(begin(v), end(v), dinheiro - l);
  return *ii;
}

int Maior(int l, vector<int> &v) {
  auto ii = upper_bound(begin(v), end(v), l);
  return *ii;
}

signed main() {

  int n;
  while (cin >> n) {
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
      int ni;
      cin >> ni;
      v[i] = ni;
    }

    int dinheiro;
    cin >> dinheiro;

    sort(begin(v), end(v));

    int p = n / 2;
    int l1 = v[p];

    int l2 = Achar(l1, dinheiro, n, v);

    while (l1 + l2 != dinheiro) {
      if (l1 > l2) {
        l1 = Maior(l1, v);
        l2 = Achar(l1, dinheiro, n, v);
      } else {
        l2 = Maior(l2, v);
        l1 = Achar(l2, dinheiro, n, v);
      }
    }

    cout << "Peter should buy books whose prices are ";
    if (l1 > l2)
      swap(l1, l2);
    cout << l1 << " and " << l2 << '.' << endl;

    cin.ignore();
  }
}
