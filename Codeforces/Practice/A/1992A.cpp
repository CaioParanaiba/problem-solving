#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    for (int j = 0; j < 5; j++) {
      if (a <= b && a <= c)
        a++;
      else if (b <= a && b <= c)
        b++;
      else
        c++;
    }
    int v = a * b * c;
    cout << v << endl;
  }

  return 0;
}
