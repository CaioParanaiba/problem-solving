#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        int ans=0,d=0,s=0;
        for(int i=0;i<n;i++){
            if(a[i]>=2) d++;
            else s++;
        }

        int c=0;

        for(int i=0;i<n;i++){
            if(a[i]>=2){
                ans+=a[i];
                if(d==1){
                    c+=a[i]/2;
                }
                else{
                    c+=(a[i]-2)/2;
                }
            }
        }
        if(d)ans += min(s,c);
        if(ans < 3) ans = 0;
        cout << ans << endl;


    }
}