#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;

    vector<bool> prime(n+1,1);prime[1]=false;
    vector<int> nprime(n+1,0);

    for(int i=1;i<=n;i++){
        if(!prime[i]) continue;
        for(int p=i*2;p<=n;p+=i){
            prime[p]=false;
            nprime[p]++;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(nprime[i]==2) ans++;
    }

    cout << ans << endl;

}