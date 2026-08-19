#include <bits/stdc++.h>

using namespace std;

struct DSU{
  vector<int> p,sz;
  int comps;

  DSU(int n): p(n+1),sz(n+1,1),comps(n) {iota(p.begin(),p.end(),0);}

  int find(int a){
    if(p[a]==a) return a;
    return p[a]=find(p[a]);
  }

  bool unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return false;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
    return true;
  }

  bool same(int a,int b) {return find(a)==find(b);}
};

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n,m,k;
  cin >> n >> m >> k;

  DSU dsu(n);

  vector<pair<int,int>> edg(m);
  for(auto &[a,b] : edg) cin >> a >> b;

  vector<tuple<string,int,int>> q(k);

  for(auto &[s,a,b] : q) cin >> s >> a >> b;

  vector<bool> ans;

  int qq=0;

  for(int i=k-1;i>=0;i--){
    auto [s,a,b] = q[i];
    if(s=="cut") dsu.unite(a,b);
    else{
      ans.push_back(dsu.same(a,b));
      qq++;
    }
  }

  for(int i=qq-1;i>=0;i--) cout << (ans[i] ? "YES\n" : "NO\n");
}
