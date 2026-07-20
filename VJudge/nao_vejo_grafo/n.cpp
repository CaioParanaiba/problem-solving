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

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  auto bfs = [&](int inicio) -> vector<int> {
    vector<int> dis(n + 1, INF);
    queue<int> q;
    dis[inicio] = 0;
    q.push(inicio);

    while (!q.empty()) {
      auto u = q.front();
      q.pop();

      for (auto v : adj[u]) {
        if (dis[v] == INF) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }
    }
    return dis;
  };

  vector<int> dis1 = bfs(1);
  int extremoA = 1;
  for (int i = 1; i <= n; i++) {
    if (dis1[i] > dis1[extremoA]) {
      extremoA = i;
    }
  }

  vector<int> dis2 = bfs(extremoA);
  int diametro = 0;
  for (int i = 1; i <= n; i++) {
    diametro = max(diametro, dis2[i]);
  }

  cout << diametro << endl;
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
