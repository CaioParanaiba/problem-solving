#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long

int main() {

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> adj[n + 1];
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({w, b});
  }

  vector<int> d(n + 1, 1e9);
  d[1] = 0;
  vector<int> pai(n + 1, 0);
  pai[1] = -1;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, 1});

  while (pq.size()) {
    auto [w, v] = pq.top();
    pq.pop();

    if (w > d[v])
      continue;
    for (auto [wu, u] : adj[v]) {
      if (w + wu < d[u]) {
        d[u] = w + wu;
        pq.push({d[u], u});
        pai[u] = v;
      }
    }
  }

  if (pai[n] == 0)
    cout << -1 << '\n';
  else {
    stack<int> sk;
    int atual = n;
    sk.push(atual);
    while (pai[sk.top()] != -1) {
      atual = pai[atual];
      sk.push(atual);
    }
    string sp = "";
    while (sk.size()) {
      cout << sp << sk.top();
      sp = " ";
      sk.pop();
    }
    cout << '\n';
  }

  return 0;
}
