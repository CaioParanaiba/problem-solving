#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<int> t(n);
    for(auto &i : t) cin >> i;

    deque<pair<int,int>> dq;
    dq.push_back({t[0],0});

    for(int i=1;i<n;i++){
        if(dq.size() && (dq.front().first + k - (i-dq.front().second))<t[i]) continue;
        if(dq.size() && t[i]<=dq.front().first){
            while(dq.size() && t[i]<=dq.front().first) dq.pop_front();
        }
        
        dq.push_back({t[i],i});
    }

    int ans=1e9;
    int ii=dq.back().second;
    int count=k;
    for(int i=ii;i>=0 && count>=0;count--,i--){
        t[i]+=count;
        ans=min(ans,t[i]);
    }

    cout << ans << endl;

}