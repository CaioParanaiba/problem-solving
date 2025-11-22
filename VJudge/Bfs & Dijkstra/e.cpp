#include <bits/stdc++.h>
using namespace std;

#define ll long long

int grid[100][100];

int Zi[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Zj[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {

  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    int n, m;
    cin >> n >> m;

    pair<int, int> a;
    pair<int, int> b;

    for (i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char x;
        cin >> x;

        if (x == '.')
          grid[i][j] = 0;
        else if (x == 'A') {
          a = {i, j};
          grid[i][j] = 0;
        } else if (x == 'B') {
          b = {i, j};
          grid[i][j] = 0;
        } else if (x == 'Z') {
          grid[i][j] = 1;
          for (int)
        }
      }
    }
  }

  return 0;
}
