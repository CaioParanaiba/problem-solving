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
  int hf, mf, ha, ma;
  char separador;
  cin >> hf >> separador >> mf;
  cin >> ha >> separador >> ma;

  int tf = hf * 60 + mf;
  int ta = ha * 60 + ma;

  int tt = tf - ta;

  cout << setfill('0') << setw(2) << tt / 60 << ':' << setfill('0') << setw(2)
       << tt % 60 << endl;
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
