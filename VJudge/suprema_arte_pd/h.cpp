#include <bits/stdc++.h>

using namespace std;

#define int long long

int MOD = 1e9+7;

signed main(){
  int n,m;
  cin >> n >> m;

  vector<string> grid(n);

  for(auto&s : grid) cin >> s;

  vector<vector<int>> pd(n,vector<int>(m,0));
  pd[0][0]=1;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j]=='#')
        continue;
      if(i) pd[i][j]=(pd[i][j]+pd[i-1][j])%MOD;
      if(j) pd[i][j]=(pd[i][j]+pd[i][j-1])%MOD;
    }
  }

  cout << pd[n-1][m-1] << endl;
}
