#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n,q;
    cin >> n;

    vector<int> c(n+1,0),v(n+1,0);

    for(int i=1;i<=n;i++){
        int ci,vi;
        cin >> ci >> vi;

        c[i]=c[i-1]+ci;
        v[i]=v[i-1]+vi;
    }


    cin >> q;

    while(q--){
        int x;
        cin >> x;

        int ans = c[x]-v[x];
        if(ans>0) cout << "COMPRA\n";
        else if(ans<0) cout << "VENDA\n";
        else cout << "NEUTRO\n";
    }
}