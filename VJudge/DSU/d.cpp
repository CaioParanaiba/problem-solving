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

void merge(int a, int b) {
  a = leader(a), b = leader(b);
  if (a != b) {
    if (S[a] < S[b])
      swap(a, b);
    P[b] = a;
    S[a] += S[b];
  }
}

bool same(int a, int b) { return leader(a) == leader(b); }

signed main() {

  int n;
  cin >> n;

  dsu_init(n);

  int day = 0;

  vector<pair<int, int>> destroy;
  vector<pair<int, int>> build;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;

    a--;
    b--;

    if (!same(a, b)) {
      merge(a, b);
    } else {
      destroy.push_back({a + 1, b + 1});
    }
  }

  for (int i = 1; i < n; i++) {
    if (!same(0, i)) {
      merge(0, i);
      day++;
      build.push_back({1, i + 1});
    }
  }

  cout << day << endl;

  for (int i = 0; i < day; i++) {
    cout << destroy[i].first << ' ' << destroy[i].second;
    cout << ' ' << build[i].first << ' ' << build[i].second << endl;
  }
}
