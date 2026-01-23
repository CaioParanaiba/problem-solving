#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

vector<int> P, S;

void dsu_init(int n) {
  P.assign(n, -1);
  S.assign(n, 1);
}

int leader(int v) {
  if (P[v] == -1)
    return v;
  return P[v] = leader(P[v]);
}

int merge(int a, int b) {
  a = leader(a), b = leader(b);
  if (a != b) {
    if (S[a] < S[b])
      swap(a, b);
    P[b] = a;
    S[a] += S[b];
  }
  return S[a];
}

bool same(int a, int b) { return leader(a) == leader(b); }

signed main() {

  int n, m;
  cin >> n >> m;

  dsu_init(n);

  int total = n;

  int tamanho_maior = 1;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    a--, b--;

    if (!same(a, b)) {
      int tamanho = merge(a, b);
      if (tamanho > tamanho_maior)
        tamanho_maior = tamanho;
      total--;
    }

    cout << total << ' ' << tamanho_maior << endl;
  }
}
