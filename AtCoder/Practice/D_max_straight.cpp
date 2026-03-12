#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n;
  cin >> n;

  map<int, int> pd;

  int maior = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    pd[x] = pd[x - 1] + 1;
    if (pd[x] > maior)
      maior = pd[x];
  }
  cout << maior << endl;
}
