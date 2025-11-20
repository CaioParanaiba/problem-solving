#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;

    if (p % 2 != 0)
      cout << 0 << '\n';
    else if (p % 4 != 0 && (p % 4) % 2 != 0)
      cout << 1 << '\n';
    else {
      int v = p / 4;
      cout << v + 1 << '\n';
    }
  }

  return 0;
}
