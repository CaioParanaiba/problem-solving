#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  string s;
  cin >> s;
  s += '$';
  int n = s.size();

  vecotr<int> p, c;

  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++)
    a[i] = {s[i], i};
  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++)
    p[i] = a.second;

  c[p[0]]

      for (auto ii : vs) {
    cout << ii.second << ' ' << ii.first << endl;
  }
}
