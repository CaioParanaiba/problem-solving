#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  vector<int> ordem;
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    ordem.push_back(x);
  }

  sort(ordem.begin(), ordem.end(), [](auto &a, auto &b) { return a > b; });

  for (int i = 0; i < 3; i++) {
    cout << ordem[i];
  }
  cout << '\n';

  return 0;
}
