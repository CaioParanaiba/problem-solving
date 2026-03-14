#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n, k, p, m;
    cin >> n >> k >> p >> m;

    deque<pair<int, int>> cards;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      cards.push_back({c, i + 1});
    }

    int p_times = 0;
    while (true) {
      int melhor = INF;
      bool win = false;
      int remove;

      deque<pair<int, int>> cards_temp;
      for (int i = 0; i < k; i++) {

        pair<int, int> c = cards.front();

        cards_temp.push_back(c);

        if (c.second == p) {
          melhor = c.first;
          win = 1;
          remove = p;

        } else if (!win && c.first < melhor) {
          remove = c.second;
          melhor = c.first;
        }
        cards.pop_front();
      }
      while (cards_temp.size()) {

        pair<int, int> c = cards_temp.back();

        if (remove == c.second) {
          cards_temp.pop_back();
          cards.push_back(c);
        } else {
          cards.push_front(cards_temp.back());
          cards_temp.pop_back();
        }
      }
      if (m < melhor)
        break;

      if (remove == p)
        p_times++;
      m -= melhor;
    }
    cout << p_times << endl;
  }
}
