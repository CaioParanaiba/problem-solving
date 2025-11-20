#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll DB(int n) {
  int b = 0;
  int pot = 1;
  while (n != 0) {
    int resto = n % 2;
    n = n / 2;
    b += resto * pot;
    pot = pot * 10;
  }
  return b;
}

ll Somaresto(ll at, ll prox) { sr = at + prox; }

int main() {

  int t;
  cin >> t;

  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;

    vector<ll> a;
    vector<ll> b;
    ll sra = 0;
    ll srb = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x = DB(x);
      a.push_back(x);
    }
  }

  return 0;
}
