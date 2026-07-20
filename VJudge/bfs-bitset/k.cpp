#include <bits/stdc++.h>
#include <sstream>
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

bool ligados(string s1, string s2) {
  if (s1.size() != s2.size())
    return false;
  int diff = 0, n = s2.size();
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i])
      diff++;
    if (diff > 1)
      return false;
  }

  return true;
}

void solve() {
  map<string, int> mp;
  vector<string> dic;

  string s;
  while (cin >> s && s != "*") {
    dic.push_back(s);
  }

  int n = dic.size();
  for (int i = 0; i < n; i++)
    mp[dic[i]] = i;

  vector<vector<int>> adj(n);

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (ligados(dic[i], dic[j])) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  cin.ignore();
  string linha;

  while (getline(cin, linha) && !linha.empty()) {
    string inicio, fim;
    stringstream ss(linha);
    ss >> inicio >> fim;

    int i = mp[inicio];
    int j = mp[fim];

    vector<int> dis(n, 1e9);
    dis[i] = 0;

    queue<int> q;
    q.push(i);

    while (q.size()) {
      auto u = q.front();
      q.pop();

      for (auto v : adj[u]) {
        if (dis[v] > dis[u] + 1) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }
    }

    cout << inicio << " " << fim << " " << dis[j] << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    if (t > 0)
      cout << endl;
  }

  return 0;
}
