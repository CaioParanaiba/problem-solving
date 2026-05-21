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
const int maxn = 200005;

vector<int> adj[maxn];
bool vis[maxn];
int filhos[maxn];

void dfs(int u, int p) {

  int total = 0;
  bool f = true;
  for (auto v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      total += filhos[v];
      f = false;
    }
  }
  if (f)
    filhos[u] = 1;
  else
    filhos[u] = total;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    adj[i].clear();
    vis[i] = 0;
    filhos[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 1);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << filhos[x] * filhos[y] << endl;
  }
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
