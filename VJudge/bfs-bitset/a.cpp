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

int di[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dj[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve() {
  string start, end;
  while (cin >> start >> end) {

    int c1 = start[0] - 'a' + 1;
    int r1 = start[1] - '0';

    int c2 = end[0] - 'a' + 1;
    int r2 = end[1] - '0';

    vector<vector<int>> dist(9, vector<int>(9, 0));
    vector<vector<bool>> vis(9, vector<bool>(9, false));

    queue<pair<int, int>> q;

    vis[r1][c1] = true;
    q.push({r1, c1});

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      if (i == r2 && j == c2)
        break;

      for (int k = 0; k < 8; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];

        if (ii >= 1 && jj >= 1 && ii <= 8 && jj <= 8 && !vis[ii][jj]) {
          vis[ii][jj] = true;
          dist[ii][jj] = dist[i][j] + 1;
          q.push({ii, jj});
        }
      }
    }

    cout << "To get from " << start << " to " << end << " takes "
         << dist[r2][c2] << " knight moves." << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
