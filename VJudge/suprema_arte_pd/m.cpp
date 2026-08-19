#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main(){
  string s;
  cin >> s;

  int n=s.size();
  int m=13;

  vector<vector<long long>> pd(n+1,vector<long long>(m,0));
  pd[0][0]=1;

  for(int i=1;i<=n;i++){
    for(int j=0;j<m;j++){
      if(!pd[i-1][j]) continue;

      if(s[i-1]=='?'){
        for(int d=0;d<10;d++){
          pd[i][(j*10+d)%m]=(pd[i][(j*10+d)%m]+pd[i-1][j])%MOD;
        }
      }
      else{
        int d = s[i-1]-'0';
        pd[i][(j*10+d)%m]=(pd[i][(j*10+d)%m]+pd[i-1][j])%MOD;
      }
    }
  }

  cout << pd[n][5] << endl;
}
