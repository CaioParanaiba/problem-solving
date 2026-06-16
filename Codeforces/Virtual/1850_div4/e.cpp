#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n,c;
    cin >> n >> c;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int esq=0,dir=1e9,ans=0;

    int m;
    while(esq<=dir){
        m = esq + (dir - esq) / 2;
        int areat=0;
        for(int i=0;i<n;i++){
            int area=(2*m+a[i]);
            areat+=area*area;
            if(areat>c) break;
        }

        
        if(areat==c) break;
        else if(areat>c) dir=m-1;
        else esq=m+1;

    }

    cout << m << endl;
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int t =1;
    cin >> t;
    while(t--){
        solve();
    }
}