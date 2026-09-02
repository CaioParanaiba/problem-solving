#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<vector<int>> adj(n+1);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> match(n+1),vis(n+1);

  int ans=0;

  auto dfs = [&](auto&&self, int u,int p)->void{
    vis[u]=true;

    for(auto v : adj[u]){
      if(vis[v]) continue;
      self(self,v,u);
    }

    if(match[u] || match[p] || u==p) return;

    ans++;
    match[u]=true;
    match[p]=true;
  };

  dfs(dfs,1,1);

  cout << ans << endl;

}
