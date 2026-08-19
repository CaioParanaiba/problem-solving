#include <bits/stdc++.h>

using namespace std;

struct DSU{
  vector<int> p,sz,points;
  int comps;
  DSU(int n): p(n+1),sz(n+1,1),points(n+1,0),comps(n) {iota(p.begin(),p.end(),0);}

  int find(int a){
    while(p[a]!=a) a=p[a];
    return a;
  }

  bool unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return false;
    if(sz[a]<sz[b]) swap(a,b);
    points[b]-=points[a];
    p[b]=a;
    sz[a]+=sz[b];
    return true;
  }

  bool same(int a,int b){
    return find(a)==find(b);
  }

  void add(int a,int x){
    points[find(a)]+=x;
  }

  int get(int a){
    int soma=0;
    while(p[a]!=a){
      soma+=points[a];
      a=p[a];
    }
    return soma+points[a];
  }
};

int main(){
  int n,m;
  cin >> n >> m;
  DSU dsu(n);

  while(m--){
    string s;
    cin >> s;

    if(s=="add"){
      int x,y;
      cin >> x >> y;
      dsu.add(x,y);
    }
    else if(s=="join"){
      int x,y;
      cin >> x >> y;
      dsu.unite(x,y);
    }
    else{
      int x;
      cin >> x;
      cout << dsu.get(x) << endl;
    }
  }
}
