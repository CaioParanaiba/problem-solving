#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;

  cin >> n;

  vector<vector<int>> adj(n);
  vector<int> grup(n,0);
  for(int i=0;i<n-1;i++){
    int x;
    cin >> x;
    x--;
    adj[x].push_back(i+1);
  }

  auto dfs = [&](auto&&self,int u)->int{
    int total=0;
    for(auto v : adj[u]){
      total+=self(self,v)+1;
    }
    grup[u]=total;
    return total;
  };

  dfs(dfs,0);

  for(int i=0;i<n;i++) cout << grup[i] << ' ';
  cout << endl;

}
