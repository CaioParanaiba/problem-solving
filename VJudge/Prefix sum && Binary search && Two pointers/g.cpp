#include <bits/stdc++.h>

using namespace std;

#define int long long

int combi(int x){
    return (x*(x-1))/2;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int l=1,r=1e9*2;
        int ans=0;
        while(l<=r){
            int m = (l+r)/2;

            if(combi(m)<=n){
                ans=m;
                l=m+1;
            }
            else r=m-1;;
        }

        

        cout << ans + n - combi(ans)<< endl;
    }
}