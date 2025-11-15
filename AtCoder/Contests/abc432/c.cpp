#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  ll n, x, y;
  cin >> n >> x >> y;

  bool possivel = true;
  ll a1;
  ll min_l1_possivel, max_l1_possivel;
  ll soma_c = 0;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    if (i == 0) {
      a1 = ai;
    }

    ll ci_resto = x * (a1 - ai) % (y - x);
    if (ci_resto != 0) {
      possivel = false;
      break;
    }

    ll ci = x * (a1 - ai) / (y - x);

    soma_c += ci;

    if (i == 0) {
      min_l1_possivel = 0;
      max_l1_possivel = a1;
    }

    ll lim_inf_i = -ci;
    ll lim_sup_i = ai - ci;

    min_l1_possivel = max(min_l1_possivel, lim_inf_i);
    max_l1_possivel = min(max_l1_possivel, lim_sup_i);

    if (min_l1_possivel > max_l1_possivel) {
      possivel = false;
      break;
    }
  }

  if (possivel) {
    ll l1_otimo = max_l1_possivel;
    ll total_l = (n * l1_otimo) + soma_c;

    cout << total_l << '\n';
  }
  //  cout << "yes\n";
  else
    cout << -1 << '\n';
  //  cout << "no\n";

  return 0;
}
