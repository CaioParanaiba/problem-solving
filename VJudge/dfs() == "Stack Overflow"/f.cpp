#include <bits/stdc++.h>
using namespace std;

#define ll long long

int max_distancia = -1;
int no_mais_longe = -1;

void DFS(int at,int pai,int distancia, vector<vector<int>>&adj)
{
  if(distancia>max_distancia)
  {
    max_distancia = distancia;
    no_mais_longe = at;
  }

  for(auto ii : adj[at])
  {
    if(ii != pai)
    {
      DFS(ii,at,distancia+1,adj);
    }
  }
}

int main() {

  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for(int i=0;i<n-1;i++)
  {
    int x,y;
    cin >> x >> y;
    
    x--;
    y--;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  DFS(0,0,0,adj);
  DFS(no_mais_longe,no_mais_longe,0,adj);

  cout << max_distancia << endl;


  return 0;
}
