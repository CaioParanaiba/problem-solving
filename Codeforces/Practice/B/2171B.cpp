#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      v[j] = a;
      if (j != 0 && j != n - 1 && v[j] == -1)
        v[j] = 0;
    }
    if (v[0] == -1 && v[n - 1] == -1) {
      v[0] = 0;
      v[n - 1] = 0;
    } else if (v[0] == -1)
      v[0] = v[n - 1];
    else if (v[n - 1] == -1)
      v[n - 1] = v[0];

    int sum = v[n - 1] - v[0];
    if (sum < 0)
      sum = sum * -1;
    cout << sum << endl;
    for (int j = 0; j < n; j++) {
      cout << v[j];
      if (j != n - 1)
        cout << ' ';
    }
    cout << endl;
  }

  return 0;
}
