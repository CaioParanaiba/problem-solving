#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n,m;
  cin >> n >> m;

  vector<vector<pair<int,int>>> adj(n,0);
  vector<int> dist(n,-1);
  dist[0]=0;

  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    
    adj[a].push_back({c,b});
  }

  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,0});

  while(pq.size())
  {
    auto[w,u] = pq.top();
    pq.pop();

    for(auto[wv,v]:adj[u])
    {
      if((dist[u]!=-1 && w+wv<dist[u]) || dist[u]==-1)
      {
        dist[u]=w+wv;
        pq.push(dist[v],v);
      }
    }
  }




  return 0;
}
