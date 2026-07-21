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

  vector<vector<pii>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  vector<int> dis(n + 1, 1e18);
  dis[1] = 0;

  priority_queue<pair<int, int>> pq;

  pq.push({dis[1], 1});
  while (pq.size()) {
    auto [d, u] = pq.top();
    pq.pop();

    d = -d;

    if (d > dis[u])
      continue;

    for (auto [v, w] : adj[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pq.push({-dis[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dis[i] << (i == n ? "\n" : " ");
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
