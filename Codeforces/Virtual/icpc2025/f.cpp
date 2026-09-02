#include <bits/stdc++.h>

using namespace std;

#define int long long

int MOD = 1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> x(q+1);

    auto exp = [&] (auto&&exp,int a, int e)->int{
        if(e==0) return 1;
        if(e&1) return exp(exp,a, e-1)%MOD;
        int fds=exp(exp,a, e/2)%MOD;
        return (fds*fds)%MOD;
    };

    int inv2=500000004;
    for(int i=1;i<=q;i++)cin >> x[i];

    vector<int> ans(n+1,0);
    int s=0;
    for(int j=q;j>0;j--){
        
        ans[x[j]]=(ans[x[j]]+(s*inv2)%MOD)%MOD;

        s=((x[j]+s)%MOD*inv2)%MOD;
    }

    ans[1]=(ans[1]+s)%MOD;

    for(int i=1;i<=n;i++) cout << ans[i] << endl;

}