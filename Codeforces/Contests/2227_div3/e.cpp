#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int ans=0;
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1]){
            ans+=a[i]-a[i+1];
            a[i]=a[i+1];
        }
    }

    map<int,int> sobra;
    for(auto i : a) sobra[i]++;

    //cout << sobra[2] << endl;

    int ans1=0;
    for(int i=n-1;i>=0;i--){
        //cout << "para i: " << i << " com a[i]: " << a[i] << " valor: " << sobra[a[i]] << endl;
        //cout << "qual o maior: " << ans1 << " ou " << sobra[a[i]]-1 << endl;
        ans1 = max(ans1,sobra[a[i]]-1);
        //cout << "Escolhido: " << ans1 << endl;
        sobra[a[i]]--;
    }

    cout << ans + ans1 << endl;
}

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}