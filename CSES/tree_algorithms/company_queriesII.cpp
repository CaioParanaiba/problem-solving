#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  int limit = log2(n) + 1;
  vector<vector<int>> adj(n + 1), bl(n + 1, vector<int>(limit));

  bl[1][0] = -1;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    adj[x].push_back(i);
    adj[i].push_back(x);
    bl[i][0] = x;
  }

  for (int j = 1; j < limit; j++) {
    for (int i = 1; i <= n; i++) {
      if (bl[i][j - 1] == -1)
        bl[i][j] = -1;
      else
        bl[i][j] = bl[bl[i][j - 1]][j - 1];
    }
  }

  vector<int> level(n + 1, 0 : wq);

  auto dfs = [&](int)
}
