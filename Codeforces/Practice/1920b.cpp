#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <functional>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve1() {
  int n, k, x;
  cin >> n >> k >> x;

  vector<int> game(n);
  for (int i = 0; i < n; i++) {
    cin >> game[i];
  }

  sort(game.begin(), game.end(), greater<int>());

  vector<int> pref(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + game[i];
  }

  int melhor = -1e18;

  for (int i = 0; i <= k; i++) {
    int bobx = min(n, i + x);

    int soma_rest = pref[n] - pref[i];

    int soma_bob = pref[bobx] - pref[i];

    int melhor_atual = soma_rest - 2 * soma_bob;

    melhor = max(melhor, melhor_atual);
  }

  cout << melhor << endl;
}

void solve() {
  int n, k, x;
  cin >> n >> k >> x;

  vector<int> game(n);
  vector<int> prf(n + 1);
  prf[n] = 0;

  for (int i = 0; i < n; i++) {
    cin >> game[i];
  }
  sort(game.begin(), game.end(), greater<int>());
  for (int i = n - 1; i >= 0; i--) {
    prf[i] = prf[i + 1] + game[i];
  }

  int melhor = -1e18;
  for (int i = 0; i <= k; i++) {
    melhor = max(melhor, prf[i] + 2 * (prf[i + x] - prf[i]));
  }

  cout << melhor;
}

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve1();
  }
}
