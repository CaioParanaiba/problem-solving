#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
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

    string s;
    cin >> s;

    vector<bool> visitado(n, 0);
    int at = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (visitado[at] == 0) {
        p++;
        visitado[at] = 1;
      }

      char c = s[at];
      if (c == 'R') {
        at++;
      } else {
        at--;
      }
    }
    cout << p << endl;
  }
}
