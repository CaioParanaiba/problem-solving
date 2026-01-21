#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int nd = 0;

    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        if (i * i == x)
          nd++;
        else
          nd += 2;
      }
    }

    cout << nd << endl;
  }

  return 0;
}
