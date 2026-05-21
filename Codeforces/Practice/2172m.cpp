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
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> adj(n + 1);
  vi ty(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> ty[i];

  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vi dist(n + 1, INF);
  dist[1] = 0;

  queue<int> q;
  vi path(k + 1, 0);
  q.push(1);

  while (q.size()) {
    auto u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (dist[u] + 1 < dist[v]) {
        dist[v] = dist[u] + 1;
        q.push(v);
        path[ty[v]] = max(path[ty[v]], dist[v]);
      }
    }
  }

  for (int i = 1; i <= k; i++)
    cout << path[i] << (i == k ? '\n' : ' ');
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
