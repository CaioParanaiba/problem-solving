#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int n,k;
  cin >> n >> k;

  vector<int> stone(n);
  for(int i=0;i<n;i++) cin >> stone[i];

  vector<int> pd(n,1e18);

  pd[0]=0;

  for(int i=1;i<n;i++){
    for(int j=i-k;j<i;j++){
      if(j<0) continue;
      int custo = abs(stone[i]-stone[j]);
      pd[i]=min(pd[i],pd[j]+custo);
    }
  }

  cout << pd[n-1] << endl;
}
