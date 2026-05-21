#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//#define int long long

// const int MOD = 1e9 + 7;
// const int INF = 1e18;

void solve() {
  long long s, k, m;
  cin >> s >> k >> m;

  long long v = m / k;
  long long topo;

  if (v % 2 == 0) {
    topo = s;
  } else {
    topo = min(s, k);
  }

  long long tempo0 = m % k;
  
  long long tempo = max((long long)0, topo - tempo0);

  cout << tempo << endl;
}

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
