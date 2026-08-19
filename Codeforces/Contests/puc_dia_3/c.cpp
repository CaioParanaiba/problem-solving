#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> city(m);
  for (int i = 0; i < m; i++)
    cin >> city[i];

  vector<int> dis(n + 1, 1e9);

  queue<int> q;
  dis[city[0]] = 0;
  q.push(city[0]);

  while (q.size()) {
    auto u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }

  int maiorno = 0, no = city[0];
  for (auto i : city) {
    if (maiorno < dis[i]) {
      maiorno = dis[i];
      no = i;
    }
  }

  vector<int> dis1(n + 1, 1e9);
  vector<int> pai(n + 1, -1);

  dis1[no] = 0;
  q.push(no);

  while (q.size()) {
    auto u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (dis1[v] > dis1[u] + 1) {
        dis1[v] = dis1[u] + 1;
        q.push(v);
        pai[v] = u;
      }
    }
  }

  int maiorno1 = 0, no1 = city[0];
  for (auto i : city) {
    if (maiorno1 < dis1[i]) {
      maiorno1 = dis1[i];
      no1 = i;
    }
  }

  bool possivel = true;
  if (dis[no1] & 1)
    possivel = false;

  int meio = no1;
  if (possivel) {
    for (int i = 0; i < dis1[no1] / 2; i++) {
      meio = pai[meio];
    }

    vector<int> dis2(n + 1, 1e9);

    dis2[meio] = 0;
    q.push(meio);

    while (q.size()) {
      auto u = q.front();
      q.pop();

      for (auto v : adj[u]) {
        if (dis2[v] > dis2[u] + 1) {
          dis2[v] = dis2[u] + 1;
          q.push(v);
        }
      }
    }

    int equilibrio = dis2[city[0]];
    for (auto i : city) {
      if (equilibrio != dis2[i]) {
        possivel = false;
        break;
      }
    }
  }

  if (possivel)
    cout << "YES\n" << meio << endl;
  else
    cout << "NO\n";
}
