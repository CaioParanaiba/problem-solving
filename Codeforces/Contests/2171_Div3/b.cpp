#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;

    vector<int> a;
    vector<int> b;

    int sa = 0;
    int sb = 0;
    for (int l = 0; l < n; l++) {
      int ai;
      cin >> ai;
      a.push_back(ai);
      sa += ai;
    }
    for (int l = 0; l < n; l++) {
      int bi;
      cin >> bi;
      b.push_back(bi);
      sb += bi;
    }

    // impar Ajisai
    // par Mai

    for (int i = 1; i <= n; i++) {
      if (i % 2 != 0) {
        // Ajisai
        if (sa % 2 == 0 && a[i - 1] != b[i - 1]) {
          sa += b[i - 1] - a[i - 1];
          sb += a[i - 1] - b[i - 1];
        }
      } else {
        if (sb % 2 == 0 && a[i - 1] != b[i - 1]) {
          sa += b[i - 1] - a[i - 1];
          sb += a[i - 1] - b[i - 1];
        }
      }
    }

    if (sa % 2 == sb % 2)
      cout << "Tie\n";
    else if (sa % 2 == 1)
      cout << "Ajisai\n";
    else
      cout << "Mai\n";
  }

  return 0;
}
