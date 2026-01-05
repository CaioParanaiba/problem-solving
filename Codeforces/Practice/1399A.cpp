#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define ll long long

int main() {

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int j = 0; j < n; j++) {
      int element;
      cin >> element;
      pq.push(element);
    }
    bool possivel = true;
    int a = pq.top();
    for (int j = 0; j < n - 1; j++) {
      pq.pop();
      int b = pq.top();

      if (b - a > 1)
        possivel = false;
      a = b;
    }
    if (possivel)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
