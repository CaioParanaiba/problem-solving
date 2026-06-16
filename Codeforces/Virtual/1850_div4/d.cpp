#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(),a.end());

    int ans=0;
    bool po=true;
    for(int i=0;i<n-1;i++){
        int total=1;
        while(i<n-1 && a[i+1]-a[i]<=k){
            total++;
            i++;
        }
        if(i<n-1 && a[i+1]-a[i]>k) po=false;
        ans = max(ans,total);
    }

    if(po) ans=n;

    cout << n-ans << endl;
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