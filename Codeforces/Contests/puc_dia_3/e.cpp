#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define int long long;

signed main() {
  double a, c;
  cin >> a >> c;
  double l = sqrt(c * c + a * a) / 2;
  double r = a * c / (4 * l);

  double retangulo = ((c / 2 * a / 2) / 2) * 4;
  double circulo = 3.1415925635 * r * r;
  double losangulo = a * c - retangulo - circulo;

  printf("%.8lf %.8lf %.8lf\n", retangulo, losangulo, circulo);
}
