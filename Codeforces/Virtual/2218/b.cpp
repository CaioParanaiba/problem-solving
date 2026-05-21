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
  vi a(7);
  cin >> a[0];

  int maior = a[0];

  int sum = a[0];
  for (int i = 1; i < 7; i++) {
    cin >> a[i];
    maior = max(maior, a[i]);
    sum += a[i];
  }

  sum = -(sum - maior) + maior;

  cout << sum << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
