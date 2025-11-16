#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long

int main() {

  int n;
  int casos = 0;
  while (cin >> n) {
    if (casos != 0)
      cout << '\n';
    map<string, int> cidades;
    map<int, string> cidades_id;
    vector<vector<int>> adj(1);

    int num_cidades = 0;
    for (int i = 0; i < n; i++) {
      string x, y;
      cin >> x >> y;

      if (!cidades.count(x)) {
        cidades[x] = num_cidades;
        cidades_id[num_cidades] = x;
        num_cidades++;
        adj.resize(num_cidades);
      }
      if (!cidades.count(y)) {
        cidades[y] = num_cidades;
        cidades_id[num_cidades] = y;
        num_cidades++;
        adj.resize(num_cidades);
      }

      adj[cidades[x]].push_back(cidades[y]);
      adj[cidades[y]].push_back((cidades[x]));
    }

    vector<int> pai(num_cidades, -1);

    string at, dest;
    cin >> at >> dest;

    if (!cidades.count(at) || !cidades.count(dest)) {
      cout << "No route\n";
    } else {
      vector<bool> vis(num_cidades, 0);
      queue<int> qu;

      qu.push(cidades[at]);
      vis[cidades[at]] = 1;

      while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        for (auto v : adj[u]) {
          if (!vis[v]) {
            qu.push(v);
            vis[v] = 1;
            pai[v] = u;
          }
        }
      }

      stack<string> ordem;

      ordem.push(dest);
      int p = pai[cidades[dest]];
      while (p != -1) {
        ordem.push(cidades_id[p]);
        p = pai[p];
      }

      if (ordem.top() != at)
        cout << "No route\n";

      else {

        while (ordem.top() != dest) {
          cout << ordem.top() << ' ';
          ordem.pop();
          cout << ordem.top() << '\n';
        }
        casos++;
      }
    }
    cin.ignore();
  }

  return 0;
}
