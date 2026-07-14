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
  int t;
  cin >> t;

  while (t) {
    if (t == 1) {
      cout << "Discarded cards:\n";
      cout << "Remaining card: 1\n";
    } else {
      deque<int> c(t);
      for (int i = 0; i < t; i++)
        c[i] = i + 1;

      cout << "Discarded cards: ";
      while (c.size() != 2) {
        cout << c.front() << ", ";
        c.pop_front();
        c.push_back(c.front());
        c.pop_front();
      }

      cout << c.front() << "\n";

      cout << "Remaining card: " << c.back() << endl;
    }
    cin >> t;
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
