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

  vector<int> d(n+1,0);

  vector<bool> vis(n+1);

  auto dfs = [&](auto&&self, int u)->void{

    vis[u]=true;

    for(auto v : adj[u]){
      if(vis[v]) continue;
      //cout << u << ' ' << v << ' ' << d1[u]+1 << ' ' << d1[v] << endl;
      d[v]=d[u]+1;
      self(self,v);
    }
  };

  dfs(dfs,1);

  int maior=0,no=1;
  for(int i=1;i<=n;i++){
    if(maior<d[i]){
      maior=d[i];
      no=i;
    }
    d[i]=0;
    vis[i]=false;
  }

  dfs(dfs,no);
  int ans=0;
  for(int i=1;i<=n;i++){
    ans=max(ans,d[i]);
  }

  cout << ans << endl;

}
