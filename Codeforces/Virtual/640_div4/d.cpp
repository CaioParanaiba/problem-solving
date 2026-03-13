#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;

    deque<int> game;

    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      game.push_back(c);
    }

    int a = 0, b = 0, m = 0;

    a = game.front();
    game.pop_front();
    m++;
    int meta = a + 1;

    bool a_last = true;
    while (game.size()) {
      if (meta >= b && a_last) {
        b += game.back();
        game.pop_back();
      } else if (meta >= a && !a_last) {
        a += game.front();
        game.pop_front();
      } else {
        a_last = !a_last;
        meta = (a > b) ? a + 1 : b + 1;
        m++;
      }
    }

    string sp = " ";
    cout << m << sp << a << sp << b << endl;
  }
}
