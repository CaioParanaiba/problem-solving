#include <bits/stdc++.h>
using namespace std;

#define ll long long

void DFS(int at, vector<vector<int>> &adj, vector<bool> &vis) {
  vis[at] = true;
  for (auto i : adj[at]) {
    if (!vis[i])
      DFS(i, adj, vis);
  }
}

int main() {

  int t;
  cin >> t;

  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
      int pi;
      cin >> pi;

      p[i] = pi;
    }

    queue<pair<int, int>> raiz;
    vector<vector<int>> adj(n);
    raiz.push({p[0], 0});
    while (raiz.size()) {
      auto [pu, u] = raiz.front();
      raiz.pop();
      for (int i = u + 1; i < n; i++) {
        if (pu < p[i]) {
          adj[u].push_back(i);
          adj[i].push_back(u);
        } else {
          raiz.push({p[i], i});
        }
      }
    }

    DFS(0, adj, vis);

    bool possivel = true;
    for (int i = 0; i < n; i++) {
      if (!vis[i])
        possivel = false;
    }

    if (possivel)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
