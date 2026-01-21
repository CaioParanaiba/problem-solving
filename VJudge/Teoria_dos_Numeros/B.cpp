#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n;
  cin >> n;

  int sum = 0;

  for (int i = 1; i <= n / 2; i++) {
    sum += i * (n / i);
  }
  cout << sum << endl;
  sum += (n / 2 + 1 + n) * (n - n / 2) / 2;

  cout << sum << endl;

  return 0;
}
