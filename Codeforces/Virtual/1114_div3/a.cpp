#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> a(3);
        for(auto&i:a) cin >> i;

        sort(a.begin(),a.end());

        int ans=0;
        while(a[0]!=a[1] && a[1]!=a[2]){
            a[2]--;
            a[0]++;
            ans++;
            sort(a.begin(),a.end());
        }
        cout << ans << endl;
    }
}