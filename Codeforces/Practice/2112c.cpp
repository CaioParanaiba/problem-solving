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

  vi a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int total = 0;
  int maior = a[n - 1];

  for (int i = 2; i < n; i++) {

    int alvo = max(a[i], maior - a[i]);

    int l = 0;
    int r = i - 1;

    while (l < r) {
      if (a[l] + a[r] > alvo) {
        total += r - l;
        r--;
      } else
        l++;
    }
  }

  cout << total << endl;
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
