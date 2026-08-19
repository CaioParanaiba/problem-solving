#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;

  vector<int> p(n+1),sz(n+1,1);
  iota(p.begin(),p.end(),0);

  auto find = [&](auto&& self,int a)->int{
    if(p[a]==a) return a;
    return p[a]=self(self,p[a]);
  };

  auto unionp = [&](int a,int b)->void{
    a=find(find,a),b=find(find,b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
  };

  auto same = [&](int a,int b)->bool{
    if(find(find,a)==find(find,b)) return true;
    return false;
  };

  for(int i=0;i<k;i++){
    string s;
    int a,b;
    cin >> s >> a >> b;

    if(s=="union") unionp(a,b);
    else cout << (same(a,b) ? "YES\n" : "NO\n");
  }
}
