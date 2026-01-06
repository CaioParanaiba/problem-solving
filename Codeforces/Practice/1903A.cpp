#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    bool possivel = true;
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      v[j] = a;
      if (j > 0) {
        if (v[j] < v[j - 1])
          possivel = false;
      }
    }
    if (k > 1 || possivel)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
