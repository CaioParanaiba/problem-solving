#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void Pontos(vector<int> &p, int n) {
  if (n == 1) {
  }
}

signed main() {

  int n;
  cin >> n;

  vector<int> p;
  map<int, int> freq;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (!freq.count(a))
      p.push_back(a);
    freq[a]++;
  }

  sort(p.begin(), p.end());
}
