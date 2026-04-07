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

void solve() {
  string p, s;
  cin >> p >> s;

  vector<pair<int, char>> pp, ss;

  int contador = 1;
  for (int i = 1; i < p.size(); i++) {
    if (p[i - 1] == p[i])
      contador++;
    else {
      pp.push_back({contador, p[i - 1]});
      contador = 1;
    }
  }
  pp.push_back({contador, p[p.size() - 1]});
  contador = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i - 1] == s[i])
      contador++;
    else {
      ss.push_back({contador, s[i - 1]});
      contador = 1;
    }
  }
  ss.push_back({contador, s[s.size() - 1]});

  bool possivel = true;
  if (pp.size() != ss.size())
    possivel = false;
  else {
    for (int i = 0; i < pp.size(); i++) {
      if (pp[i].first * 2 < ss[i].first || pp[i].first > ss[i].first ||
          pp[i].second != ss[i].second)
        possivel = false;
    }
  }

  cout << (possivel ? "YES" : "NO") << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
