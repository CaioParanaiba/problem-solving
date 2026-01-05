#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int dif = (a > b) ? a - b : b - a;
    int s = dif / 10;
    if (dif % 10 != 0)
      s++;
    cout << s << endl;
  }

  return 0;
}
