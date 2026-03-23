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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    string sp = "";
    for (int i = 0; i < n; i++) {
      int maior = 0, menor = 0;
      for (int j = i + 1; j < n; j++) {
        if (a[j] > a[i])
          maior++;
        if (a[j] < a[i])
          menor++;
      }
      cout << sp << max(maior, menor);
      sp = " ";
    }
    cout << endl;
  }
}
