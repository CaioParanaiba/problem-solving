#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int n,x;
  cin >> n >> x;

  vector<int> coins(n);
  for(auto&c : coins) cin >> c;

  vector<int> pd(x+1,1e18);
  pd[0]=0;

  for(int i=1;i<=x;i++){
    for(auto c : coins){
      if(i<c || pd[i-c]==1e18)
        continue;
      pd[i]=min(pd[i],pd[i-c]+1);
    }
  }

  cout << (pd[x]!=1e18 ? pd[x] : -1) << endl;
}
