#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void dfs(int at, vector<vector<int>> &adj, vector<bool> &vis,
         vector<int> &valores, map<int, int> &freq, int &repetidos,
         vector<bool> &resposta) {
  vis[at] = 1;
  int valor_atual = valores[at];

  freq[valor_atual]++;
  if (freq[valor_atual] == 2)
    repetidos++;

  if (repetidos > 0)
    resposta[at] = 1;
  else
    resposta[at] = 0;

  for (auto i : adj[at]) {
    if (!vis[i])
      dfs(i, adj, vis, valores, freq, repetidos, resposta);
  }

  if (freq[valor_atual] == 2)
    repetidos--;
  freq[valor_atual]--;
}

signed main() {
  int V, A;
  cin >> V;
  A = V - 1;

  vector<vector<int>> adj(V);
  vector<bool> vis(V);
  vector<int> valores(V);
  map<int, int> freq;
  int repetidos = 0;
  vector<bool> resposta(V);

  for (int i = 0; i < V; i++) {
    int val;
    cin >> val;

    valores[i] = val;
  }

  for (int i = 0; i < A; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(0, adj, vis, valores, freq, repetidos, resposta);

  for (int i = 0; i < V; i++) {
    if (resposta[i])
      cout << "Yes";
    else
      cout << "No";
    cout << endl;
  }
}
