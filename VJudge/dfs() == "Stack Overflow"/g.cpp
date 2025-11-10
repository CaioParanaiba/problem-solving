#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool DFS(int at,vector<vector<int>>&adj,vector<bool>&vis)
{
  vis[at]=1;

  if(adj[at].size()==2)
  {
    for(auto ii : adj[at])
    {
      if(!vis[ii]) DFS(ii,adj,vis);
    }
    return true;
  }
  else{
    return false;
  }
}

int main() {

  int n,m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<bool> vis(n);

  for(int i=0;i<m;i++)
  {
    int x,y;
    cin >> x >> y;
    x--;
    y--;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int ciclos = 0;
  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {
      if(DFS(i,adj,vis)) ciclos++;
    }
  }

  cout << ciclos << endl;

  return 0;
}
