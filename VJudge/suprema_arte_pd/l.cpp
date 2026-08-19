#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n,x;
  cin >> n >> x;

  vector<int> coins(n);
  for(auto& c : coins) cin >> c;

  vector<int> pd(x+1,0);

  const int MOD = 1e9+7;

  pd[0]=1;
  for(int i=1;i<=x;i++){
    for(int c=0;c<n;c++){
      if(i<coins[c])
        continue;
      pd[i]= (pd[i]+pd[i-coins[c]])%MOD;
    }
  }


  cout << pd[x] << endl;


}
