#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int x, y, r;
  cin >> x >> y >> r;

  int idademulti = (x - y) / (r - 1);
  int resto = (x - y) % (r - 1);
  if (idademulti >= y && resto == 0)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
