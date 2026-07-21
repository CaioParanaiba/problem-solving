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

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, 1});

  vector<int> cont(n + 1, 0);

  vector<int> ans;
  while (pq.size()) {
    auto [d, u] = pq.top();
    pq.pop();

    cont[u]++;

    if (cont[u] > k)
      continue;

    if (u == n) {
      ans.push_back(d);
      if (cont[n] == k)
        break;
    }

    for (auto [v, w] : adj[u]) {
      if (cont[v] < k) {
        pq.push({w + d, v});
      }
    }
  }

  for (auto i : ans)
    cout << i << ' ';
  cout << endl;
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
