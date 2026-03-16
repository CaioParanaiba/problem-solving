#include <bits/stdc++.h>
#include <numeric>
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
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int g_ab = gcd(a, b);
    int g_ac = gcd(a, c);
    int g_bc = gcd(b, c);
    int g_abc = gcd(g_ab, c);

    // cout << g_ab << ' ' << g_ac << ' ' << g_bc << ' ' << g_abc << endl;

    int mdc_ab = (a / g_ab) * b;
    int mdc_ac = (a / g_ac) * c;
    int mdc_bc = (c / g_bc) * b;
    int mdc_abc = (mdc_ab / gcd(mdc_ab, c)) * c;

    // cout << mdc_ab << ' ' << mdc_ac << ' ' << mdc_bc << ' ' << mdc_abc <<
    // endl;

    int r_ab = m / mdc_ab;
    int r_ac = m / mdc_ac;
    int r_bc = m / mdc_bc;
    int r_abc = m / mdc_abc;

    int r_a = m / a;
    int r_b = m / b;
    int r_c = m / c;

    // cout << r_ab << ' ' << r_ac << ' ' << r_bc << ' ' << r_abc << endl <<
    // endl;

    int trio = r_abc;
    int so_ab = r_ab - trio;
    int so_ac = r_ac - trio;
    int so_bc = r_bc - trio;

    int so_a = r_a - so_ab - so_ac - trio;
    int so_b = r_b - so_ab - so_bc - trio;
    int so_c = r_c - so_ac - so_bc - trio;

    int res_a = so_a * 6 + so_ab * 3 + so_ac * 3 + trio * 2;
    int res_b = so_b * 6 + so_ab * 3 + so_bc * 3 + trio * 2;
    int res_c = so_c * 6 + so_ac * 3 + so_bc * 3 + trio * 2;

    cout << res_a << " " << res_b << " " << res_c << endl;
  }
}
