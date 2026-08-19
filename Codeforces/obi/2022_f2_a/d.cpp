#include <bits/stdc++.h>

using namespace std;
#define int long long


typedef struct {
  int v, t, p;
} rotas;

signed main() {
  int P, n, m;
  cin >> P >> n >> m;

  vector<vector<rotas>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b, t, p;
    cin >> a >> b >> t >> p;

    adj[a].push_back({b, t, p});
    adj[b].push_back({a, t, p});
  }

  vector<vector<int>> dis(n + 1,vector<int>(P+1,1e18));

  priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, greater<>> pq;

  int x,y;
  cin >> x >> y;

  dis[x][0]=0;
  pq.push({{0,0},x});

  int ans=-1;

  while(pq.size()){
    auto [tp,u] = pq.top();
    auto [tu,pu] = tp;
    pq.pop();

    if(u==y){
      ans=tu;
      break;
    }

    for(auto [v,tv,pv] : adj[u]){
      int custot=tv+tu, custop=pv+pu;
      if(custop>P) continue;
      if(dis[v][custop]>custot){
        dis[v][custop]=custot;
        pq.push({{custot,custop},v});
      }
    }
  }

  cout << ans << endl;
 }
