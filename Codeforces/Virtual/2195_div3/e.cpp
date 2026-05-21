#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using vi = vector<int>;
using pii = pair<int, int>;

const int mod = 1e9 + 7;
const int INF = 1e18;

void solve() {
  int n;
  cin >> n;

  vi tempo(n + 1);
  vi custo(n + 1);
  vi D(n + 1, 0), E(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> E[i] >> D[i];

    if (E[i] == 0 && D[i] == 0)
      custo[i] = 0;
    else
      custo[i] = -1;
  }

  queue<int> bfs;
  vi ordem;
  bfs.push(1);

  while (bfs.size()) {
    auto u = bfs.front();
    bfs.pop();
    ordem.push_back(u);

    if (E[u])
      bfs.push(E[u]);
    if (D[u])
      bfs.push(D[u]);
  }

  for (int i = n - 1; i >= 0; i--) {
    int u = ordem[i];
    if (custo[u] == -1)
      custo[u] = (custo[D[u]] + custo[E[u]] + 4) % mod;
  }

  tempo[1] = (custo[1] + 1) % mod;

  for (int i = 0; i < n; i++) {
    int u = ordem[i];
    if (E[u])
      tempo[E[u]] = (tempo[u] + custo[E[u]] + 1) % mod;
    if (D[u])
      tempo[D[u]] = (tempo[u] + custo[D[u]] + 1) % mod;
  }

  for (int i = 1; i <= n; i++)
    cout << tempo[i] << (i == n ? '\n' : ' ');
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
