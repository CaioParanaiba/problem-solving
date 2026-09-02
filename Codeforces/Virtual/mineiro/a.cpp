#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n,h;
    cin >> n >> h;

    vector<int> x(n+1),y(n+1),raio(n+1);

    for(int i=1;i<=n;i++) cin >> x[i] >> y[i] >> raio[i];

    vector<vector<pair<double,int>>> adj(n+2);

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double dis=max(0.0,hypot(x[i]-x[j],y[i]-y[j])-raio[i]-raio[j]);

            adj[i].push_back({dis,j});
            adj[j].push_back({dis,i});
        }
        adj[i].push_back({max(0LL,h-y[i]-raio[i]),n+1});
        adj[0].push_back({max(0LL,y[i]-raio[i]),i});
    }
    adj[0].push_back({h,n+1});

    vector<double> dis(n+2,1e18);
    dis[0]=0.0;
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<>> pq;
    pq.push({0.0,0});

    while(pq.size()){
        auto [d,u] = pq.top();
        pq.pop();

        if(d>dis[u]) continue;

        for(auto [dv,v] : adj[u]){
            if(dis[v]>dis[u]+dv){
                dis[v]=dis[u]+dv;
                pq.push({dis[v],v});
            }
        }
    }

    cout << fixed <<  setprecision(15);
    cout << dis[n+1] << endl;
}