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

int c = 0;

void solve() {
  int u, v;
  cin >> u >> v;
  while (u && v) {
    vector<vector<int>> adj(101, vector<int>(101, 1e18));
    while (u && v) {
      adj[u][v] = 1;
      cin >> u >> v;
    }

    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= 100; j++) {
        if (i == j)
          adj[i][j] = 0;
      }
    }

    for (int k = 1; k <= 100; k++) {
      for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
      }
    }

    int n = 0;
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= 100; j++) {
        if (adj[i][j] == 1e18 || i == j)
          continue;
        n++;
        sum += adj[i][j];
      }
    }

    printf("Case %lld: average length between pages = %.3lf clicks\n", ++c,
           (double)sum / n);
    cin >> u >> v;
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
