#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    set<char> sb;
    int pt = 0;

    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (sb.count(c)) {
        pt += 1;
      } else {
        pt += 2;
        sb.insert(c);
      }
    }
    cout << pt << endl;
  }

  return 0;
}
