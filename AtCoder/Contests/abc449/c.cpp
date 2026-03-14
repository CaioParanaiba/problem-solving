#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, l, r;
  cin >> n >> r >> l;

  vector<char> s(n + 1);
  vector<int> ind(n + 1);
  ind[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    ind[i] = i;
  }

  int pares = 0;

  for (int i = 1; i <= n; i++) {
    int inicio = -n, fim = -n;
    auto intera_inicio = lower_bound(ind.begin() + 1, ind.end(), l + i);
    auto intera_fim = lower_bound(ind.begin() + 1, ind.end(), r + i);

    // cout << "Quando meu i: " << i << "tenho meu inicio em " << *intera_fim
    //<< endl;
    if (intera_inicio != ind.end())
      inicio = *intera_inicio;
    else
      inicio = n;
    if (intera_fim != ind.end())
      fim = *intera_fim;

    if (fim > 0 && inicio > 0) {
      // cout << fim << ' ' << inicio << endl;
      for (int j = fim; j <= inicio; j++) {
        // cout << "Valor i " << i << " Valor j " << j << " " << s[i] << s[j]
        //<< endl;
        if (s[i] == s[j])
          pares++;
      }
    }
  }

  cout << pares << endl;
}
