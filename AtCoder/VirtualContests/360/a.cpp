#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  bool m = false, r = false;
  bool an = false;
  for (int i = 0; i < 3; i++) {
    char a;
    cin >> a;
    if (a == 'R')
      r = 1;
    else if (a == 'M')
      m = 1;
    if (r == 1 && m == 0)
      an = 1;
  }

  if (an)
    cout << "Yes\n";
  else
    cout << "No\n";
}
