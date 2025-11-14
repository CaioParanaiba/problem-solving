#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n,m;
  cin >> n >> m;

  vector<int> parede(n,0);

  for(int i=0;i<m;i++)
  {
    int r,l;
    cin >> r >> l;
    for(int j=r-1;j<l;j++)
    {
      parede[j]++;
    }
  }

  for(int i=0;i<n;i++)
  {
    cout << parede[i] << ' ';
  }
  cout << endl;

  cout << parede[0] << '\n';

  return 0;
}
