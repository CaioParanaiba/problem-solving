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

int caso = 1;

int get_id(map<int, int> &id_map, int &nodes_count, int u) {
  if (!id_map.count(u)) {
    id_map[u] = nodes_count++;
  }
  return id_map[u];
}

void solve(int NC) {
  map<int, int> id_map;
  int nodes_count = 0;

  vector<vi> adj(35);

  for (int i = 0; i < NC; i++) {
    int u, v;
    cin >> u >> v;
    int id_u = get_id(id_map, nodes_count, u);
    int id_v = get_id(id_map, nodes_count, v);

    adj[id_u].pb(id_v);
    adj[id_v].pb(id_u);
  }

  int start_node, ttl;
  while (cin >> start_node >> ttl && (start_node != 0 || ttl != 0)) {

    int ans = nodes_count;

    if (id_map.count(start_node)) {
      int start_id = id_map[start_node];
      vector<bool> vis(35, false);
      queue<pair<int, int>> q;

      vis[start_id] = true;
      ans--;
      q.push({start_id, ttl});

      while (!q.empty()) {
        auto [u, tu] = q.front();
        q.pop();

        if (tu == 0)
          continue;

        for (auto v : adj[u]) {
          if (vis[v])
            continue;

          vis[v] = true;
          ans--;
          q.push({v, tu - 1});
        }
      }
    }
    cout << "Case " << caso++ << ": " << ans
         << " nodes not reachable from node " << start_node
         << " with TTL = " << ttl << "." << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int NC;
  // Leitura contínua até o NC ser 0
  while (cin >> NC && NC != 0) {
    solve(NC);
  }

  return 0;
}
