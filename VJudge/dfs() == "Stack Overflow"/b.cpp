#include <bits/stdc++.h>
using namespace std;

#define ll long long

int vx[]={+1,+1,+1,0,0,-1,-1,-1};
int vy[]={+1,0,-1,+1,-1,+1,0,-1};

void DFS(int i,int j,int n,vector<vector<int>>& adj,vector<vector<bool>>& vir)
{
  vir[i][j] = 1;

  for(int ii=0;ii<8;ii++)
  {
    int dx = i + vx[ii];
    int dy = j + vy[ii];

    if(dx>=0 && dx<n && dy>=0 && dy<n && !vir[dx][dy] && adj[dx][dy]==1)
    {
      DFS(dx,dy,n,adj,vir);
    }
  }
}


int main() {

  int n;
  int caso=1;
  while(cin>>n)
  {
    vector<vector<int>> adj(n, vector<int>(n));
    vector<vector<bool>> vir(n, vector<bool>(n,false));

    for(int i=0;i<n;i++)
    {
      string linha;
      cin >> linha;
      for(int j=0;j<n;j++)
      {
        adj[i][j] = linha[j] - '0';
      }
    }

    int war = 0; 

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(adj[i][j]==1 && !vir[i][j])
        {
          war++;
          DFS(i,j,n,adj,vir);
        }
      }
    }
    
    cout << "Image number " << caso << " contains " << war << " war eagles." << endl;
    caso++;
  }

  return 0;
}
