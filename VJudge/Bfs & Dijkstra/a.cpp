#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long

int main() {

  int casos = 1;

  int nc;
  cin >> nc;
  while (nc != 0) {

    map<int, int> nodulos;
    vector<vector<int>> adj(1);

    int no = 0;
    for (int i = 0; i < nc; i++) {
      int x, y;
      cin >> x >> y;

      if (!nodulos.count(x)) {
        nodulos[x] = no;
        no++;
        adj.resize(no);
      }
      if (!nodulos.count(y)) {
        nodulos[y] = no;
        no++;
        adj.resize(no);
      }

      adj[nodulos[x]].push_back(nodulos[y]);
      adj[nodulos[y]].push_back(nodulos[x]);
    }

    int initi, ttl;
    cin >> initi >> ttl;
    while (initi != 0 || ttl != 0) {

      int acess = 1;

      vector<int> D(no, 0);
      queue<int> qu;
      vector<bool> vis(no, 0);

      qu.push(nodulos[initi]);
      vis[nodulos[initi]] = 1;
      D[nodulos[initi]] = 0;

      while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto v : adj[u]) {
          if (!vis[v]) {
            qu.push(v);
            vis[v] = 1;
            D[v] = D[u] + 1;
            if (D[v] <= ttl)
              acess++;
          }
        }
      }
      int no_acess = no - acess;
      cout << "Case " << casos << ": " << no_acess
           << " nodes not reachable from node " << initi
           << " with TTL = " << ttl << '.' << endl;

      cin >> initi >> ttl;
      casos++;
    }

    cin >> nc;
  }

  return 0;
}
