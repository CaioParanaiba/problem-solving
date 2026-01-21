#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n;
  cin >> n;

  vector<int> q(n);

  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    q[i] = h;
  }

  sort(q.begin(), q.end());

  cin >> n;

  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;

    // cout << h << endl;
    auto u = upper_bound(q.begin(), q.end(), h);
    auto l = lower_bound(q.begin(), q.end(), h);

    l--;

    if (l < q.begin())
      cout << 'X';
    else
      cout << *l;

    cout << ' ';

    if (u == q.end())
      cout << 'X';
    else
      cout << *u;

    cout << endl;
  }

  return 0;
}
