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
  unordered_map<string, string> dict;
  string linha;

  while (getline(cin, linha)) {
    if (linha.empty())
      break;

    stringstream ss(linha);
    string eng, foreign;
    ss >> eng >> foreign;

    dict[foreign] = eng;
  }

  string query;
  while (cin >> query) {
    if (dict.count(query)) {
      cout << dict[query] << endl;
    } else {
      cout << "eh" << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
