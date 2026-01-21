#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n, q;
  cin >> n >> q;

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    int pi;
    cin >> pi;
    p[i] = pi;
  }

  sort(p.begin(), p.end());

  vector<ll> sp(n + 1);
  sp[0] = 0;
  for (int i = 1; i <= n; i++) {
    sp[i] = sp[i - 1] + p[i - 1];
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    ll s = sp[n - l + r] - sp[n - l];

    cout << s << '\n';
  }

  return 0;
}
