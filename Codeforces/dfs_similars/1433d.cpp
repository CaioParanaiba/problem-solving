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

  vector<pair<int, int>> ordem(n - 1);

  queue<pair<int, int>> q;

  pair<int, int> p1, p2;
  cin >> p1.first;
  p1.second = 1;

  int j = 0;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if (x != p1.first) {
      ordem[j] = {1, i + 1};
      j++;
      p2 = {x, i + 1};
    } else {
      q.push({x, i + 1});
    }
  }

  if (q.size() != n - 1) {

    cout << "YES\n";
    for (int i = 0; i < j; i++)
      cout << ordem[i].first << ' ' << ordem[i].second << endl;

    // cout << "part 2\n";
    while (q.size()) {
      cout << p2.second << ' ' << q.front().second << endl;
      q.pop();
    }
  } else
    cout << "NO\n";
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
