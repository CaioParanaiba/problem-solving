#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;

    vector<pair<int,int>> c(n);

    for(int i=0;i<n;i++) cin >> c[i].first;
    for(int i=0;i<n;i++) cin >> c[i].second;

    sort(c.begin(),c.end(),[](auto a,auto b){
        return (a.first-a.second)>(b.first-b.second);
    });

    for(int i=0;i<n;i++){
        if(c[i].first<c[i].second){
            cout << -1 << endl;
            return 0;
        }
    }

    int ans=0;
    for(int i=0;i<n-1;i++){
        ans+=c[i].first;
    }
    ans+=c[n-1].second;

    cout << ans << endl;

}