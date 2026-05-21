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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vi grau(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    grau[u]++;
    grau[v]++;
  }

  vector<bool> vis(n + 1, false);

  int total = 0;

  queue<int> qu;

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      qu.push(i);
      vis[i] = true;

      bool ciclo = true;

      while (qu.size()) {
        int u = qu.front();
        qu.pop();

        if (grau[u] != 2)
          ciclo = false;

        for (auto v : adj[u]) {
          if (!vis[v]) {
            qu.push(v);
            vis[v] = true;
          }
        }
      }
      if (ciclo)
        total++;
    }
  }

  cout << total << endl;
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
