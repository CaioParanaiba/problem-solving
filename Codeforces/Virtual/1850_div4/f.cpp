#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    vector<int> a(n+1,0);
    vector<int> armadilha(n+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x<=n)a[x]++;
    }

    for(int i=1;i<=n;i++){
        if(a[i]==0) continue;
        for(int j=i;j<=n;j+=i){
            armadilha[j]+=a[i];
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans = max(ans,armadilha[i]);

    cout << ans << endl;

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