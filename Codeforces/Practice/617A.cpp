#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int c;
  cin >> c;
  int step = 0;
  while (c != 0) {
    if (c >= 5)
      c -= 5;
    else if (c >= 4)
      c -= 4;
    else if (c >= 3)
      c -= 3;
    else if (c >= 2)
      c -= 2;
    else if (c >= 1)
      c--;
    step++;
  }
  cout << step << endl;

  return 0;
}
