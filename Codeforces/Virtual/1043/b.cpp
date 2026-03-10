#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int pot = 10;
    vector<int> valores;
    while ((n / (1 + pot)) > 1) {
      if ((n / (1 + pot)) * (1 + pot) == n) {
        valores.push_back(n / (1 + pot));
      }
      pot *= 10;
    }

    sort(valores.begin(), valores.end());
    if (valores.size() > 0) {
      cout << valores.size() << endl;
      string s = "";
      for (auto i : valores) {
        cout << s << i;
        s = " ";
      }
    } else
      cout << 0;
    cout << endl;
  }
}
