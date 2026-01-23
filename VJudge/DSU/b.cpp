#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int leader(int v, vector<int> &P) {
  if (P[v] == -1)
    return v;
  return P[v] = leader(P[v], P);
}

void merge(int a, int b, vector<int> &P, vector<int> &S, vector<int> &Sv) {
  a = leader(a, P), b = leader(b, P);
  if (a != b) {
    if (S[a] < S[b])
      swap(a, b);
    S[a] += S[b];
    Sv[a] += Sv[b];
    P[b] = a;
  }
}

bool same(int a, int b, vector<int> &P) { return leader(a, P) == leader(b, P); }

signed main() {

  int n, m, q;
  cin >> n >> m >> q;

  int grid[n][m];

  vector<int> P(n * m, -1), S(n * m, 1), Sv(n * m, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;

      if (c == '*')
        grid[i][j] = 1;
      else
        grid[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        for (int k = 0; k < 4; k++) {
          int dii, djj;
          dii = i + di[k];
          djj = j + dj[k];

          if (dii >= 0 && dii < n && djj >= 0 && djj < m && grid[dii][djj] == 1)
            Sv[i * m + j]++;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        for (int k = 0; k < 2; k++) {
          int dii = i + di[k];
          int djj = j + dj[k];

          if (dii >= 0 && dii < n && djj >= 0 && djj < m &&
              grid[dii][djj] == 0 && !same(i * m + j, dii * m + djj, P))
            merge(i * m + j, dii * m + djj, P, S, Sv);
        }
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << Sv[leader(a * m + b, P)] << endl;
  }
}
