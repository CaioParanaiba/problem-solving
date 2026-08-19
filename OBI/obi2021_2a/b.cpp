#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n, m;
  cin >> n >> m;

  vector<multiset<string>> linha(n), coluna(m);
  vector<int> vallinha(n), valcoluna(m);

  map<string, int> mp;

  vector<vector<string>> mat(n, vector<string>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string s;
      cin >> s;
      mat[i][j] = s;
      mp[s] = -1;
    }
    cin >> vallinha[i];
  }

  for (int j = 0; j < m; j++)
    cin >> valcoluna[j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      linha[i].insert(mat[i][j]);
      coluna[j].insert(mat[i][j]);
    }
  }

  int dist = mp.size();
  int t = 0;
  while (t != dist) {
    // procurar
    string valor;

    for (int i = 0; i < n; i++) {
      if (!linha[i].size())
        continue;
      if (linha[i].count(*linha[i].begin()) == linha[i].size()) {
        valor = *linha[i].begin();
        vallinha[i] = vallinha[i] / ((int)linha[i].count(valor));
        mp[valor] = vallinha[i];
        linha[i].erase(valor);
        t++;

        for (int k = 0; k < n; k++) {
          if (linha[k].find(valor) == linha[k].end())
            continue;
          vallinha[k] = vallinha[k] - mp[valor] * linha[k].count(valor);
          linha[k].erase(valor);
        }

        for (int k = 0; k < m; k++) {
          if (coluna[k].find(valor) == coluna[k].end())
            continue;
          valcoluna[k] = valcoluna[k] - mp[valor] * coluna[k].count(valor);
          coluna[k].erase(valor);
        }
      }
    }

    for (int j = 0; j < m; j++) {
      if (!coluna[j].size())
        continue;
      if (coluna[j].count(*coluna[j].begin()) == coluna[j].size()) {
        valor = *coluna[j].begin();
        valcoluna[j] = valcoluna[j] / ((int)coluna[j].count(valor));
        mp[valor] = valcoluna[j];
        coluna[j].erase(valor);
        t++;

        for (int k = 0; k < n; k++) {
          if (linha[k].find(valor) == linha[k].end())
            continue;
          vallinha[k] = vallinha[k] - mp[valor] * linha[k].count(valor);
          linha[k].erase(valor);
        }

        for (int k = 0; k < m; k++) {
          if (coluna[k].find(valor) == coluna[k].end())
            continue;
          valcoluna[k] = valcoluna[k] - mp[valor] * coluna[k].count(valor);
          coluna[k].erase(valor);
        }
      }
    }
  }

  for (auto a : mp) {
    cout << a.first << ' ' << a.second << endl;
  }
}
