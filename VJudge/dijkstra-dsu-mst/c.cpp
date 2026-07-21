#include <bits/stdc++.h>
#include <vector>
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

  vector<vector<int>> dis(n + 1, vector<int>(2, 1e18));
  dis[1][0] = 0;
  dis[1][1] = 0;

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq;
  pq.push({0, 1, 0});

  while (pq.size()) {
    auto [wu, u, t] = pq.top();
    pq.pop();

    if (wu > dis[u][t])
      continue;

    for (auto [v, wv] : adj[u]) {
      if (dis[v][0] > dis[u][0] + wv) {
        dis[v][0] = dis[u][0] + wv;
        pq.push({dis[u][0] + wv, v, 0});
      }

      if (dis[v][1] > dis[u][1] + wv) {
        dis[v][1] = dis[u][1] + wv;
        pq.push({dis[u][1] + wv, v, 1});
      }

      if (dis[v][1] > dis[u][0] + wv / 2) {
        dis[v][1] = dis[u][0] + wv / 2;
        pq.push({dis[u][0] + wv / 2, v, 1});
      }
    }
  }

  cout << min(dis[n][0], dis[n][1]) << endl;
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
