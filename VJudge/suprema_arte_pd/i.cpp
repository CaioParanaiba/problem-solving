#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<long double> prob(n+1);

  for(int i=1;i<=n;i++) cin >> prob[i];


  vector<double> pd(n+1,0);
  pd[0]=1;

  for(int i=1;i<=n;i++){
    for(int j=i;j>=0;j--){
      pd[j]=pd[j]*(1-prob[i]);
      if(j) pd[j]+=pd[j-1]*prob[i];
    }
  }

  long double ans=0;
  for(int i=n;i>n/2;i--) ans+= pd[i];

  printf("%.9Lf\n",ans);
}
