#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first > b.first;
}

signed main() {

  int n;
  cin >> n;

  vector<pair<int, int>> v;
  map<int, int> m;

  int dif = 0;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (m.find(a) == m.end()) {
      v.push_back({a, 0});
      m.insert({a, 1});
      dif++;
    } else {
      int valor = m[a] + 1;
      m[a] = valor;
    }
  }

  for (int i = 0; i < dif; i++) {
    int x = v[i].first;
    int c = v[i].second;
    if (m.find(x - 1) != m.end())
      c += m[x - 1] * (x - 1);
    if (m.find(x + 1) != m.end())
      c += m[x + 1] * (x + 1);

    v[i] = {x, c};
  }

  sort(v.begin(), v.end(), comp);

  for (auto ii : v) {
    cout << ii.first << '\t' << ii.second << endl;
  }

  int pontos = 0;
  for (auto ii : v) {
    if (m.find(ii.first) != m.end()) {
      pontos += ii.first * m[ii.first];
      m.erase(ii.first - 1);
      m.erase(ii.first + 1);
    }
  }

  cout << pontos << endl;
}
