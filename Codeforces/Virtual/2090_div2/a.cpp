#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve1() {
  int x, y, a;
  cin >> x >> y >> a;

  int soma = x + y;

  int resto = a % soma;

  if (x > resto)
    cout << "NO\n";
  else
    cout << "YES\n";
}

void solve() {
  int x, y, a;
  cin >> x >> y >> a;

  bool lk = 1;

  int total = 0;

  while (total <= a) {
    lk = !lk;

    total += (lk) ? y : x;
  }

  if (lk)
    cout << "YES\n";
  else
    cout << "NO\n";
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
