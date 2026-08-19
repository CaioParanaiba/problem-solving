#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n, w;
  cin >> n >> w;

  vector<pair<int, int>> itens(n);

  int maxvalor = 0;
  for (auto &[w, v] : itens) {
    cin >> w >> v;
    maxvalor += v;
  }

  vector<int> pd(maxvalor + 1,1e18);
  pd[0]=0;

  for(auto [peso,valor] : itens){
    for(int j=maxvalor;j>=valor;j--){
      pd[j]=min(pd[j],pd[j-valor]+peso);
    }
  }

  for(int i=maxvalor;i>=0;i--){
    if(pd[i]<=w){
      cout << i << endl;
      return 0;
    }
  }

}
