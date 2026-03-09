#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int INF = 1e18;

signed main() {
  int n, q;
  cin >> n >> q;

  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    int A;
    cin >> A;
    b.push_back({A, i});
  }

  sort(b.begin(), b.end());

  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;

    set<int> s;
    for (int j = 0; j < k; j++) {
      int B;
      cin >> B;
      s.insert(B - 1);
    }

    for (int j = 0; j < n; j++) {
      if (!s.count(b[j].second)) {
        cout << b[j].first << endl;
        break;
      }
    }
    s.clear();
  }
}
