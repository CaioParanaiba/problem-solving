#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int a;
  cin >> a;

  if (400 % a == 0) {
    int b = 400 / a;
    cout << b << '\n';
  } else
    cout << -1 << '\n';

  return 0;
}
