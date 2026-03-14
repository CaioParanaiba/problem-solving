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
    vector<int> freq(n * n + 1, 0);

    int nn = n * n;
    bool possivel = true;
    for (int i = 0; i < nn; i++) {
      int x;
      cin >> x;
      freq[x]++;
      if (freq[x] > (n * (n - 1)))
        possivel = false;
    }

    if (possivel)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
