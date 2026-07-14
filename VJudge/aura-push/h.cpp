#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
  int n, m, r, c, x, y;
  cin >> n >> m >> r >> c >> x >> y;
  r--;
  c--;

  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  vector<vector<int>> esq(n, vector<int>(m, INF));
  deque<pair<int, int>> dq;

  esq[r][c] = 0;
  dq.push_back({r, c});

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  while (!dq.empty()) {
    auto [linha, col] = dq.front();
    dq.pop_front();

    for (int i = 0; i < 4; i++) {
      int nl = linha + dr[i];
      int nc = col + dc[i];

      if (nl >= 0 && nl < n && nc >= 0 && nc < m && grid[nl][nc] != '*') {
        int custo = (i == 2 ? 1 : 0);
        if (esq[linha][col] + custo < esq[nl][nc]) {
          esq[nl][nc] = esq[linha][col] + custo;
          if (custo == 0) {
            dq.push_front({nl, nc});
          } else {
            dq.push_back({nl, nc});
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (esq[i][j] != INF) {
        int gastos_esq = esq[i][j];
        int gastos_dir = gastos_esq + (j - c);
        if (gastos_esq <= x && gastos_dir <= y) {
          ans++;
        }
      }
    }
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
