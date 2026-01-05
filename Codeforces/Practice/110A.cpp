#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  ll int n;
  int nl = 0;
  cin >> n;
  while (n > 0) {
    if (n % 10 == 7 || n % 10 == 4)
      nl++;
    n = n / 10;
  }

  if (nl == 4 || nl == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
