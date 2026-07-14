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
  int n, d;
  cin >> n >> d;

  deque<int> dq(n);

  for (int i = 0; i < n; i++)
    cin >> dq[i];

  while (d--) {
    int x = dq.front();
    dq.pop_front();
    dq.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    cout << dq[i] << ((i < n - 1) ? " " : "\n");
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
