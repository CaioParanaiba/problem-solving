#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n;
  cin >> n;

  vector<int> v;
  map<int, int> m;

  int nn = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (m.find(a) == m.end()) {
      m[a] = 1;
      v.push_back(a);
      nn++;
    } else {
      int valor = m[a] + 1;
      m[a] = valor;
    }
  }

  sort(v.begin(), v.end());

  vector<int> pontos(nn);

  pontos[0] = v[0] * m[v[0]];

  int pontos_pass = (v[1] == v[1] - 1) ? 0 : pontos[0];

  pontos[1] = pontos_pass + v[1] * m[v[1]];

  for (int i = 2; i < nn; i++) {

    if (v[i - 1] != v[i] - 1) {
      pontos_pass = max(pontos[i - 1], pontos[i - 2]);
    } else {
      pontos_pass = (i > 2) ? max(pontos[i - 2], pontos[i - 3]) : pontos[i - 2];
    }

    pontos[i] = pontos_pass + v[i] * m[v[i]];
  }

  cout << pontos[1] << endl;
}
