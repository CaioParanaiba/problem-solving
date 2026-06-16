#include <bits/stdc++.h>

using namespace std;

bool simu(vector<int>& a,int x){
    int at=0;
    for(auto d : a){
        if(x<(d-at)) return false;
        if(x==(d-at)) x--;

        at=d;
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);

        int low=0,hi;
        for(int i=0;i<n;i++) cin >> a[i];
        hi=a[n-1];

        int ans=0;
        while(hi>low){
            int m=(low+hi)/2;

            if(simu(a,m)){
                ans=m;
                hi=m;
            }
            else low=m+1;
        }
        if(simu(a,hi)) ans=hi;

        cout << ans << endl;

    }
}