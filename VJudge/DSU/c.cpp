#include <bits/stdc++.h>
#include <functional>
#include <iterator>
using namespace std;

#define endl '\n'
#define int long long

vector<int> P, S;

void dsu_init(int n) {
  S.assign(n, 1);
  P.assign(n, -1);
}

int leader(int v) {
  if (P[v] == -1)
    return v;
  return P[v] = leader(P[v]);
}

signed main() {

  int n, m;
  cin >> n >> m;

  dsu_init(n);

  vector<tuple<int, int, int>> score;
  vector<int> balls(n);

  for (int i = 0; i < n; i++) {
    int valor;
    cin >> valor;
    balls[i] = valor;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int peso = (pow(balls[i], balls[j]) + pow(balls[j], balls[i])) mod m;
      score.push_back({peso, i, j});
    }
  }

  sort(begin(score), end(score), greater<tuple<int, int, int>>());
}
