#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
  int n;
  cin >> n;

  vector<int> s;

  int an;
  cin >> an;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    int at;
    cin >> at;

    if (at > an)
      cnt++;
    else {
      s.push_back(cnt);
      cnt = 1;
    }

    an = at;
  }

  s.push_back(cnt);

  int tam = s.size();
  cout << tam << endl;
  for (int i = 0; i < tam; i++) {
    cout << s[i] << (i != tam - 1 ? " " : "\n");
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
