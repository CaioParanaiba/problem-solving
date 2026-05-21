#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

signed main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    pair<int,int> par={0,-1},impar={0,-1};


    for(int i=0;i<n;i++){
        if(a[i]%2==0) par={par.first+1,i};
        else impar={impar.first+1,i};
    }

    if(par.first==1) cout << par.second+1 << endl;
    else cout << impar.second+1 << endl;
}