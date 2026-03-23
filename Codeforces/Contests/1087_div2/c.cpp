#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;

    // int escolha = 1;
    bool achou = false;
    for (int i = 1; i <= 2 * n - 2; i += 2) {
      cout << "? " << i << ' ' << i + 1 << endl;
      int resposta;
      cin >> resposta;

      if (resposta == -1)
        return 0;

      if (resposta == 1) {
        cout << "! " << i << endl;
        achou = 1;
        break;
      }
      // escolha=i;
    }
    int resposta;
    if (achou == 0) {
      int penultimo = 2 * n - 1;
      int ultimo = 2 * n;

      cout << "? 1 " << penultimo << endl;
      cin >> resposta;
      if (resposta == -1)
        return 0;
      else if (resposta == 1) {
        cout << "! 1" << endl;
        achou = 1;
      }

      if (achou == 0) {
        cout << "? 2 " << penultimo << endl;
        cin >> resposta;
        if (resposta == -1)
          return 0;
        else if (resposta == 1) {
          cout << "! 2" << endl;
          achou = 1;
        }

        if (!achou)
          cout << "! " << ultimo << endl;
      }
    }
  }
}
