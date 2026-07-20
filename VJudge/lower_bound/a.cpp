#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int money;
    cin >> money;

    sort(all(a));

    int i = 0, j = n - 1;
    int ans_i = 0, ans_j = 0;

    while (i < j) {
      int sum = a[i] + a[j];

      if (sum == money) {
        ans_i = a[i];
        ans_j = a[j];
        i++;
        j--;
      } else if (sum < money) {
        i++;
      } else {
        j--;
      }
    }

    printf("Peter should buy books whose prices are %d and %d.\n\n", ans_i,
           ans_j);
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
