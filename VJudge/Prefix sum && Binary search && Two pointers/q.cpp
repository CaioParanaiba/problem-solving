#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> pref(n+1);pref[0]=0;

    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i-1];
    }

    int l=0,r=0;

    int leitura=0,ans=0;
    while(r!=n){
        r++;
        leitura=pref[r]-pref[l];

        while(leitura>t && l!=r){
            l++;
            leitura=pref[r]-pref[l];
        }

        ans=max(ans,r-l);
    }

    cout << ans << endl;
}