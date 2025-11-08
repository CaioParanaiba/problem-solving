#include <bits/stdc++.h>
using namespace std;

#define ll long long

void DFS(int at,int&caidos,int n,vector<vector<int>>&adj,vector<bool>&vis)
{
  vis[at]=1;
  caidos++;

  for(auto ii : adj[at])
  {
    if(!vis[ii]) DFS(ii,caidos,n,adj,vis);
  }
}

int main() {

  int t;
  cin >> t;

  for(int i=0;i<t;i++)
  {
    int n,m,l;
    cin >> n >> m >> l;

    vector<vector<int>> adj(n);
    vector<bool> vis(n);

    for(int j=0;j<m;j++)
    {
      int f,s;
      cin >> f >> s;

      adj[f-1].push_back(s-1);
    }

    int caidos = 0;
    for(int j=0;j<l;j++)
    {
      int c;
      cin >> c;
      
      if(!vis[c-1]) DFS(c-1,caidos,n,adj,vis);

    }
    cout << caidos << endl;
  }

  return 0;
}
