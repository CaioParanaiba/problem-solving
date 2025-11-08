#include <bits/stdc++.h>
using namespace std;

#define ll long long

int vx[]={-1,1,0,0};
int vy[]={0,0,-1,1};

void DFS(int y,int x,int n,int m,vector<vector<int>>&adj,vector<vector<bool>>&vis)
{
  vis[y][x]=1;

  for(int i=0;i<4;i++)
  {
    int dx = x + vx[i];
    int dy = y + vy[i];

    if(dx>=0 && dx<m && dy>=0 && dy<n && adj[dy][dx]==1 && !vis[dy][dx])
    {
      DFS(dy,dx,n,m,adj,vis);
    }
  }
}


int main() {

  int n,m;
  cin >> n >> m;

  cin.ignore();
 
  vector<vector<int>> adj(n, vector<int>(m));
  vector<vector<bool>> vis(n, vector<bool>(m,false));

  for(int i=0;i<n;i++)
  {
    string linha;
    getline(cin,linha);

    for(int j=0;j<m;j++)
    {
      if(linha[j]=='#') adj[i][j] = 0;
      else if(linha[j]=='.') adj[i][j] = 1;
    }
  }

  int rooms = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(adj[i][j]==1 && !vis[i][j])
      {
        rooms++;
        DFS(i,j,n,m,adj,vis);
      }
    }
  }

  cout << rooms << endl;

  return 0;
}
