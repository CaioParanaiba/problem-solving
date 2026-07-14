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
  while (cin >> n && n != 0) {

    while (true) {
      int primeiro_vagao;
      cin >> primeiro_vagao;

      if (primeiro_vagao == 0) {
        cout << endl;
        break;
      }

      vector<int> v(n);
      v[0] = primeiro_vagao;
      for (int i = 1; i < n; i++) {
        cin >> v[i];
      }

      stack<int> s;
      int at = 1;

      bool ans = true;
      for (int i = 0; i < n; i++) {

        while (at <= n && (s.empty() || s.top() != v[i])) {
          s.push(at);
          at++;
        }

        if (s.size() && s.top() == v[i])
          s.pop();
        else {
          ans = false;
          break;
        }
      }

      cout << (ans ? "Yes\n" : "No\n");
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
