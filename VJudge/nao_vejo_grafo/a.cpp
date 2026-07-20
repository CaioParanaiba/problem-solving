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

  vector<vi> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> vis(n + 1, 0);
  bool ans = true;

  for (int i = 1; i <= n && ans; i++) {
    if (vis[i])
      continue;

    int v_cont = 0, a_cont = 0;

    queue<int> q;
    q.push(i);
    vis[i] = true;

    while (q.size()) {
      int u = q.front();
      q.pop();
      v_cont++;
      a_cont += sz(adj[u]);

      for (auto v : adj[u]) {
        if (vis[v])
          continue;
        vis[v] = true;
        q.push(v);
      }
    }

    if (a_cont != 2 * v_cont)
      ans = false;
  }

  cout << (ans ? "Yes\n" : "No\n");
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
