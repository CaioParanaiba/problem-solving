#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    deque<int> dq;
    ll int sum = 0;

    int even = 2;
    for (int j = 0; j < n / 2; j++) {
      sum += even;
      dq.push_front(even);
      even += 2;
    }

    bool possivel = true;
    int odd = 1;
    for (int j = 0; j < n / 2; j++) {
      if (sum - odd > odd || sum - odd == 0) {
        sum -= odd;
        dq.push_back(odd);
        odd += 2;
      } else if (sum - odd > 0) {
        odd += 2;
        j--;
      } else {
        possivel = false;
        j = n / 2;
      }
    }

    if (possivel) {
      cout << "YES" << endl;
      for (int j = 0; j < n; j++) {
        cout << dq.front();
        if (j < n - 1)
          cout << ' ';
        dq.pop_front();
      }
    } else
      cout << "NO";
    cout << endl;
  }

  return 0;
}
