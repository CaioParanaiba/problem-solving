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

  while (cin >> n && n) {
    vector<int> v(n + 1, 0);

    for (int i = 0; i < n; i++)
      cin >> v[i];
    stack<int> st;

    int ans = 0;

    for (int i = 0; i <= n; i++) {
      while (st.size() && v[st.top()] > v[i]) {
        int h = v[st.top()];
        st.pop();
        int l = (st.empty()) ? i : i - st.top() - 1;
        ans = max(ans, l * h);
      }
      st.push(i);
    }

    cout << ans << endl;
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
