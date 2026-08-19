#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int n,m;
  cin >> n >> m;

  vector<vector<string>> mat(n,vector<string>(m));
  int suml[n];
  int sumc[m];

  set<string> faltam;
  set<pair<string,int>> ans;


  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> mat[i][j];
      faltam.insert(mat[i][j]);
    }
    cin >> suml[i];
  }

  for(int i=0;i<m;i++) cin >> sumc[i];

  vector<string> linhas;



  for(auto i : ans) cout << i.first << ' ' << i.second << endl;
}
