#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

  string x;
  cin >> x;

  sort(x.begin(), x.end());

  if (x[0] == '0') {
    int p;
    for (int i = 1; i < x.length(); i++) {
      if (x[i] != '0') {
        p = i;
        break;
      }
    }
    x[0] = x[p];
    x[p] = '0';
  }

  cout << x << '\n';

  return 0;
}
