#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int x,n,q;
  cin >> x >> n;

  vector<int> W;
  vector<bool> vir(n);
  for(int i=0;i<n;i++)
  {
    int w;
    cin >> w;
    W.push_back(w);
  }

  cin >> q;
  for(int i=0;i<q;i++)
  {
    int p;
    cin >> p;
    p--;
    if(!vir[p])
    {
      vir[p] = true;
      x+=W[p];
    }
    else {
      vir[p] = false;
      x-=W[p];
    }
    
    cout << x << endl;

  }

  return 0;
}

