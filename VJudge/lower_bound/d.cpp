#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }

  sort(all(v));

  for (int i = 0; i < n; i++) {
    int left = i + 1;
    int right = n - 1;
    int target = x - v[i].first;

    while (left < right) {
      int sum = v[left].first + v[right].first;

      if (sum == target) {
        cout << v[i].second << ' ' << v[left].second << ' ' << v[right].second
             << endl;
        return;
      } else if (sum < target) {
        left++;
      } else {
        right--;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;
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
