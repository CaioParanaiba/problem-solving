#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};
const char dir_char[4] = {'D', 'U', 'R', 'L'};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> mat(n);
  int start_i = -1, start_j = -1;
  int end_i = -1, end_j = -1;

  for (int i = 0; i < n; i++) {
    cin >> mat[i];
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 'A') {
        start_i = i;
        start_j = j;
      } else if (mat[i][j] == 'B') {
        end_i = i;
        end_j = j;
      }
    }
  }

  vector<vector<int>> step(n, vector<int>(m, -1));

  queue<pair<int, int>> q;
  q.push({start_i, start_j});
  step[start_i][start_j] = -2;

  bool found = false;

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    if (i == end_i && j == end_j) {
      found = true;
      break;
    }

    for (int k = 0; k < 4; k++) {
      int ii = i + di[k];
      int jj = j + dj[k];

      if (ii >= 0 && ii < n && jj >= 0 && jj < m && mat[ii][jj] != '#' &&
          step[ii][jj] == -1) {
        step[ii][jj] = k;
        q.push({ii, jj});
      }
    }
  }

  if (found) {
    cout << "YES" << endl;

    string caminho = "";
    int curr_i = end_i;
    int curr_j = end_j;

    while (curr_i != start_i || curr_j != start_j) {
      int k = step[curr_i][curr_j];
      caminho += dir_char[k];
      curr_i -= di[k];
      curr_j -= dj[k];
    }

    reverse(caminho.begin(), caminho.end());
    cout << caminho.size() << endl;
    cout << caminho << endl;
  } else {
    cout << "NO" << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
