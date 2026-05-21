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

  vector<int> dist(20005, -1);
  queue<int> q;

  q.push(n);
  dist[n] = 0;

  while (q.size()) {
    int u = q.front();
    q.pop();

    if (u == m) {
      cout << dist[u] << endl;
      return;
    }

    if (u * 2 <= 20000 && dist[u * 2] == -1) {
      dist[u * 2] = dist[u] + 1;
      q.push(u * 2);
    }

    if (u - 1 > 0 && dist[u - 1] == -1) {
      dist[u - 1] = dist[u] + 1;
      q.push(u - 1);
    }
  }

  cout << dist[m] << endl;
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
