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

int contar_divisor(int n) {
  if (n == 0)
    return 1;

  int count = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      count++;
      if (i * i != n)
        count++;
    }
  }

  return count;
}

void solve() {
  int x, y;
  cin >> x >> y;

  int soma = abs(x - y);

  int divisores = contar_divisor(soma);

  cout << divisores % 676767677 << endl;

  for (int i = 0; i < x; i++)
    cout << "1 ";
  for (int i = 0; i < y; i++)
    cout << "-1 ";
  cout << endl;
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
