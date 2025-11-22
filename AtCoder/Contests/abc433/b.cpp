#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long

int main() {

  int n;
  cin >> n;

  vector<int> altura;
  for (int i = 0; i < n; i++) {
    int pessoa = -1;
    int a;
    cin >> a;
    altura.push_back(a);
    for (int j = i - 1; j >= 0; j--) {
      if (altura[i] < altura[j]) {
        pessoa = j + 1;
        j = 0;
      }
    }

    cout << pessoa << '\n';
  }

  return 0;
}
