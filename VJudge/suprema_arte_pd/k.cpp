#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> pd(n+1,1e9);
  pd[0]=0;

  for(int i=1;i<=n;i++){
    int num = i;
    while(num!=0){
      int d = num%10;
      pd[i]=min(pd[i],pd[i-d]+1);
      num/=10;
    }
  }

  cout << pd[n] << endl;
}
