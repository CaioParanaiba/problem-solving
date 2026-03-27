#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve1() {
  int n, m;
  cin >> n >> m;

  vector<string> mat(n);
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }

  bool possivel = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '1') {

        bool cima = true;
        for (int k = 0; k < i; k++) {
          if (mat[k][j] == '0') {
            cima = false;
            break;
          }
        }

        bool esq = true;
        for (int k = 0; k < j; k++) {
          if (mat[i][k] == '0') {
            esq = false;
            break;
          }
        }

        if (!esq && !cima)
          possivel = false;
      }
    }
  }

  if (possivel)
    cout << "YES\n";
  else
    cout << "NO\n";
}

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve1();
  }
}
