#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;

    bool possivel = true;

    int vb = n / k;
    vector<int> numeros(k, vb);

    if (vb == 0)
      possivel = false;

    int resto = n % k;

    if (resto != 0) {
      numeros[0] += resto;
      if (numeros[0] % 2 != vb % 2) {
        if ((k - 1) % 2 == 0 && vb > 1) {
          for (int j = 1; j < k; j++) {
            if (j % 2 == 1)
              numeros[j]++;
            else
              numeros[j]--;
          }
        } else
          possivel = 0;
      }
    }

    if (possivel) {
      cout << "YES" << endl;
      string sp = "";
      for (auto nn : numeros) {
        cout << sp << nn;
        sp = " ";
      }
      cout << endl;
    } else
      cout << "NO" << endl;
  }
}
