#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int k, n, w;
  cin >> k >> n >> w;
  int bn = 0;
  for (int i = 1; i <= w; i++) {
    bn += i * k;
  }
  n = bn - n;
  if (n < 0)
    n = 0;
  cout << n << endl;

  return 0;
}
