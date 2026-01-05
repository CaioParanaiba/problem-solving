#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int sum_odd = 0;
    int sum_even = 0;
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a % 2 != 0)
        sum_odd++;
      else
        sum_even++;
    }
    if ((n == 2 && sum_odd != sum_even) || (n > 2 && sum_odd % 2 == 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}

/*
1 2 2 3
2
2


*/
