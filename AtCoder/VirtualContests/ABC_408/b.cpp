#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n;
  cin >> n;
  set<int> ordem;

  for(int i=0;i<n;i++)
  {
    int x;
    cin >> x;
    ordem.insert(x);
  }

  string separador = "";

  cout << ordem.size() << '\n';
  for(auto ii : ordem)
  {
    cout << separador << ii;
    separador = " ";
  }
  cout << '\n';

  return 0;
}
