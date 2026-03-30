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
  int n, k;
  cin >> n >> k;

  vi a(n);
  vi b(n);
  vector<bool> meio(n + 1, false);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i >= (n - k) && i < k)
      meio[a[i]] = true;
  }

  vi freq(n + 1, 0);
  bool possivel = true;
  for (int i = 0; i < n; i++) {
    cin >> b[i];

    if (b[i] == -1)
      continue;

    if (++freq[b[i]] > 1)
      possivel = false;

    if (i < (n - k) || i >= k) {
      if (b[i] != a[i])
        possivel = false;
    } else {
      if (b[i] != -1 && !meio[b[i]])
        possivel = false;
    }
  }

  cout << (possivel ? "YES" : "NO") << endl;
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
