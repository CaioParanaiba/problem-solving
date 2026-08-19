#include <bits/stdc++.h>

using namespace std;

string get_max_string(string a,string b){
  if(a.size()>b.size()) return a;
  return b;
}

int main(){
  string a,b;
  cin >> a >> b;

  int an=a.size(),bn=b.size();

  vector<vector<int>> pd(an+1,vector<int>(bn+1,0));

  for(int i=1;i<=an;i++){
    for(int j=1;j<=bn;j++){
      if(a[i-1]==b[j-1]) pd[i][j]=pd[i-1][j-1]+1;
      else pd[i][j]=max(pd[i-1][j],pd[i][j-1]);
    }
  }

  string ans="";

  int i=an,j=bn;
  while(i>0 && j>0){
    if(a[i-1]==b[j-1]){
      ans+=a[i-1];
      i--;
      j--;
    }
    else if(pd[i-1][j]>=pd[i][j-1]) i--;
    else j--;
  }

  reverse(ans.begin(),ans.end());

  cout << ans << endl;
}
