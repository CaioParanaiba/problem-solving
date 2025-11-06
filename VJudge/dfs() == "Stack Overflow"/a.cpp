#include <bits/stdc++.h>
using namespace std;

#define ll long long

int ChartoInt(char no)
{
  return no - 'A';
}

void DFS(int at,vector<vector<int>>& adj,vector<bool>& vis)
{
  vis[at]=1;
  for(auto i : adj[at])
  {
    if(!vis[i]) DFS(i,adj,vis);
  }
}


int main() {

  int t;
  cin >> t;
  cin.ignore();
  for(int i=0;i<t;i++)
  {
    string nos;
    cin >> nos;
    cin.ignore();

    int maior_no = ChartoInt(nos[0]);
    
    vector<vector<int>> adj(maior_no+1);
    vector<bool> vis(maior_no+1);
    while(getline(cin,nos) && !nos.empty())
    {
      int x,y;

      x = ChartoInt(nos[0]);
      y = ChartoInt(nos[1]);
      
      if(x<=maior_no && y<=maior_no){
        adj[x].push_back(y);
        adj[y].push_back(x);
      }
    }
    int grupos = 0;
    for(int ii=0;ii<=maior_no;ii++)
    {
      if(!vis[ii])
      {
        DFS(ii,adj,vis);
        grupos++;
      }
    }

    if(i>0) cout << endl;
    cout << grupos << endl;
  }

  return 0;
}
