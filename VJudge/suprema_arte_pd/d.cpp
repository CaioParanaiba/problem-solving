#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int n,w;
  cin >> n >> w;

  vector<int> pd(w+1,0);

  for(int i=0;i<n;i++){
    int p,v;
    cin >> p >> v;
    for(int j=w;j>=0;j--){
      if(j-p<0)continue;
      pd[j]=max(pd[j],pd[j-p]+v);
    }
  }

  cout << pd[w] << endl;
}
