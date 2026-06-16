#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for(int i=1;i<=n;i++){
        int w,q;
        cin >> w >> q;
        if(w<=10) a.push_back({q,i});
    }

    sort(a.begin(),a.end());

    cout << a[a.size()-1].second << endl;
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