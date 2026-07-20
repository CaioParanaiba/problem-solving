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

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void dfs(int i, int j, const vector<vector<char>> &mat,
         vector<vector<bool>> &vis, int &tamanho, bool &tocou_preto,
         bool &tocou_branco) {
  vis[i][j] = true;
  tamanho++;

  for (int k = 0; k < 4; k++) {
    int ii = i + di[k];
    int jj = j + dj[k];

    if (ii >= 0 && jj >= 0 && ii < 9 && jj < 9) {
      if (mat[ii][jj] == 'X') {
        tocou_preto = true;
      } else if (mat[ii][jj] == 'O') {
        tocou_branco = true;
      } else if (mat[ii][jj] == '.' && !vis[ii][jj]) {
        dfs(ii, jj, mat, vis, tamanho, tocou_preto, tocou_branco);
      }
    }
  }
}

bool solve() {
  int n = 9, m = 9;
  vector<vector<char>> mat(n, vector<char>(m));

  if (!(cin >> mat[0][0]))
    return false;

  int black_points = (mat[0][0] == 'X' ? 1 : 0);
  int white_points = (mat[0][0] == 'O' ? 1 : 0);

  for (int j = 1; j < m; j++) {
    cin >> mat[0][j];
    if (mat[0][j] == 'X')
      black_points++;
    else if (mat[0][j] == 'O')
      white_points++;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 'X')
        black_points++;
      else if (mat[i][j] == 'O')
        white_points++;
    }
  }

  vector<vector<bool>> vis(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '.' && !vis[i][j]) {
        int tamanho = 0;
        bool tocou_preto = false;
        bool tocou_branco = false;

        dfs(i, j, mat, vis, tamanho, tocou_preto, tocou_branco);

        if (tocou_preto && !tocou_branco)
          black_points += tamanho;
        else if (tocou_branco && !tocou_preto)
          white_points += tamanho;
      }
    }
  }

  cout << "Black " << black_points << " White " << white_points << endl;
  return true;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (solve()) {
  }

  return 0;
}
