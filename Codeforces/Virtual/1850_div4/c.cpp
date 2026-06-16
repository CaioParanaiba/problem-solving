#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve(){
    char mat[8][8];

    string s="";

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> mat[i][j];
            if(mat[i][j]!='.') s+=mat[i][j];
        }
    }

    cout << s << endl;
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