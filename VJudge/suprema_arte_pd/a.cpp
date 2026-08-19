#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int n;
  cin >> n;

  vector<int> stone(n);
  for(int i=0;i<n;i++) cin >> stone[i];

  vector<int> pd(n);
  pd[0]=0;
  pd[1]=abs(stone[1]-stone[0]);

  for(int i=2;i<n;i++){
    int custo1 = abs(stone[i]-stone[i-1]);
    int custo2 = abs(stone[i]-stone[i-2]);
    pd[i]=min(pd[i-1]+custo1,pd[i-2]+custo2);


  }

  cout << pd[n-1] << endl;
}
