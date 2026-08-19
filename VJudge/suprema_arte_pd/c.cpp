#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int n;
  cin >> n;

  array<int,3> pd;
  for(auto &x : pd) cin >> x;

  for(int i=1;i<n;i++){
    array<int,3> ganho;
    for(auto &x : ganho) cin >> x;

    array<int,3> novo;

    novo[0]=ganho[0]+max(pd[1],pd[2]);
    novo[1]=ganho[1]+max(pd[0],pd[2]);
    novo[2]=ganho[2]+max(pd[0],pd[1]);

    pd=novo;
  }

  cout << max({pd[0],pd[1],pd[2]}) << endl;
}
