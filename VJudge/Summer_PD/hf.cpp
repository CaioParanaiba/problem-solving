#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  int n;
  cin >> n;

  map<int, int> freq;
  int maior = -1;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    freq[x]++;
    if (x > maior)
      maior = x;
  }

  vector<int> pd(maior + 1, 0);

  if (freq.count(1))
    pd[1] = freq[1];

  for (int i = 2; i < maior + 1; i++) {
    pd[i] = max(pd[i - 1], pd[i - 2] + i * freq[i]);
  }

  cout << max(pd[maior], pd[maior - 1]) << endl;
}
