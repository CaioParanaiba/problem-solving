#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {

  string s;
  cin >> s;
  s+='$';
  int n = s.size();

  vector<int> pref(n),c(n);

  vector<pair<char,int>> a(n);
  for(int i=0;i<n;i++){
    a[i]={s[i],i};
  }

  sort(a.begin(),a.end());

  for(int i=0;i<n;i++) pref[i]=a[i].second;

  c[pref[0]]=0;
  for(int i=1;i<n;i++){
    if(a[i].first!=a[i-1].first) c[pref[i]]=c[pref[i-1]]+1;
    else c[pref[i]]=c[pref[i-1]];
  }

  int k=0;
  while((1<<k) < n){
    
    vector<pair<pair<int,int>,int>> pares(n);

    for(int i=0;i<n;i++){
      int esq = c[i];
      int dir = c[(i+(1<<k))%n];
      pares[i]={{esq,dir},i};
    }

    sort(pares.begin(),pares.end());

    for(int i=0;i<n;i++) pref[i]=pares[i].second;

    c[pref[0]]=0;
    for(int i=1;i<n;i++){
      if(pares[i].first == pares[i-1].first) c[pref[i]]=c[pref[i-1]];
      else c[pref[i]] = c[pref[i-1]]+1;
    }

    k++;
  }

  for(int i=0;i<n;i++) cout << pref[i] << (i==n-1 ? "\n" : " ");
}
