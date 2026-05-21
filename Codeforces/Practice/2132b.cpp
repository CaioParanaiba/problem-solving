#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long


void solve(){

    int n;
    cin >> n;
    int pot=10;
    vector<int> a;

    while(n/(pot+1)){
        if(n%(pot+1)==0) a.push_back(n/(pot+1));
        pot*=10;
    }

    sort(a.begin(),a.end());

    cout << a.size() << endl;
    if(a.size()){
        for(int i=0;i<a.size();i++){
            cout << a[i] << (i==(a.size()-1) ? "\n" : " ");
        }
    }
}

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}