#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
  int n;
  cin >> n;

  vector<int> a(n);
  for(auto &i : a) cin >> i;

  vector<int> v;

  for(auto x : a){
    auto it = lower_bound(v.begin(),v.end(),x);
    if(it==v.end()) v.push_back(x);
    else *it=x;
  }

  cout << v.size() << endl;
}
