#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

bool Comparar(vector<char> &comp, string t) {
  bool igual = true;
  int tamanho = t.size();
  for (int i = 0; i < tamanho; i++) {
    if (comp[i] != t[i])
      igual = 0;
  }
  return igual;
}

signed main() {

  string ss;
  cin >> ss;

  string t;
  cin >> t;

  int tamanho = ss.size();
  int tamanhot = t.size();

  int w = tamanho / tamanhot;
  int linhas = (tamanho % t.size() != 0) ? t.size() + 1 : t.size();

  bool possivel = false;

  while (w < tamanho && !possivel) {

    queue<char> s;
    for (auto i : ss) {
      s.push(i);
    }
    // cout << w << '\t' << linhas << endl;
    vector<vector<char>> palavra(linhas);

    int id = 0;
    int ct = 0;
    while (s.size()) {
      if (ct > w - 1) {
        ct = 0;
        id++;
      }
      // cout << "Inserido no id: " << id << " a letra " << s.front()
      //      << "Contador " << ct << endl;
      palavra[id].push_back(s.front());
      s.pop();
      ct++;
    }

    cout << "w atual \t" << w << endl;

    // for (int i = 0; i < linhas; i++) {
    // for (auto j : palavra[i]) {
    // cout << j;
    // }
    // cout << endl;
    //}

    vector<char> comp(tamanhot);
    for (int i = w - 1; i > 0; i--) {
      for (int j = 0; j < tamanhot; j++) {
        comp[j] = palavra[j][i];
        q
      }
      possivel = Comparar(comp, t);
      if (possivel && w <= linhas)
        i = 0;
      else if (possivel && w > linhas)
        possivel = 0;
    }

    cout << "penultimo" << w << endl;
    if (w >= tamanho || linhas >= tamanho)
      possivel = 0;

    w++;
    cout << "ultimo" << w << endl;
  }
  if (possivel)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
