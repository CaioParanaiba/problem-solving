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

  vector<int> dis(n+1,0);
  vector<bool> vis(n+1);

  queue<int> q;

  q.push(1);
  vis[1]=true;
  while(q.size()){
    auto u = q.front();
    q.pop();

    for(auto  v : adj[u]){
      if(vis[v]) continue;
      dis[v]=dis[u]+1;
      vis[v]=true;
      q.push(v);
    }
  }

  int no1=1,no2=1;
  int maior=0;
  for(int i=1;i<=n;i++){
    if(maior<dis[i]){
      maior=dis[i];
      no1=i;
    }
    vis[i]=false;
    dis[i]=0;
  }

  q.push(no1);
  vis[no1]=true;
  while(q.size()){
    auto u = q.front();
    q.pop();

    for(auto  v : adj[u]){
      if(vis[v]) continue;
      dis[v]=dis[u]+1;
      vis[v]=true;
      q.push(v);
    }
  }

  maior=0;
  for(int i=1;i<=n;i++){
    if(maior<dis[i]){
      maior=dis[i];
      no2=i;
    }
    vis[i]=false;
  }

  vector<int> dis2(n+1,0);
  q.push(no2);
  vis[no2]=true;
  while(q.size()){
    auto u = q.front();
    q.pop();

    for(auto  v : adj[u]){
      if(vis[v]) continue;
      dis2[v]=dis2[u]+1;
      vis[v]=true;
      q.push(v);
    }
  }

  //cout << no1 << ' ' << no2 << endl;

  for(int i=1;i<=n;i++) cout << max(dis[i],dis2[i]) << ' ';
  cout << endl;

}
