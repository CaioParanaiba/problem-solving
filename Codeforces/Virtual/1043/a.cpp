#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int casos;
  cin >> casos;
  for (int j = 0; j < casos; j++) {
    int n;
    cin >> n;
    deque<char> c;
    for (int i = 0; i < n; i++) {
      char cc;
      cin >> cc;
      c.push_back(cc);
    }

    cin >> n;
    queue<char> ordem;
    for (int i = 0; i < n; i++) {
      char cc;
      cin >> cc;
      ordem.push(cc);
    }

    for (int i = 0; i < n; i++) {
      char tipo;
      cin >> tipo;

      char p = ordem.front();
      if (tipo == 'V')
        c.push_front(p);
      else if (tipo == 'D')
        c.push_back(p);
      ordem.pop();
    }

    int t = c.size();
    for (int i = 0; i < t; i++) {
      cout << c.front();
      c.pop_front();
    }
    cout << endl;
  }
}
