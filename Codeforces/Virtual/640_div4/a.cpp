#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int t = 0;
    int pot = 1;

    vector<int> numeros;
    while (x > 0) {
      int c = x % 10;
      if (c != 0) {
        t++;
        numeros.push_back(c * pot);
      }
      pot *= 10;
      x = x / 10;
    }

    cout << t << endl;

    string sp = "";

    for (auto nn : numeros) {
      cout << sp << nn;
      sp = " ";
    }
    cout << endl;
  }
}
