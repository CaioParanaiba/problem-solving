#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n;
  cin >> n;
  vector<int> caixa(n, 0);
  int sobra = 0;

  vector<int> ordem(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ordem[i] = a - 1;
  }
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    if (caixa[ordem[i]] == 0)
      caixa[ordem[i]] = w;
    else {
      if (caixa[ordem[i]] > w) {
        sobra += w;
      } else {
        sobra += caixa[ordem[i]];
        caixa[ordem[i]] = w;
      }
    }
  }

  cout << sobra << endl;
}
