#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,x,s;
        cin >> n >> s >> x;
        vector<int> a(n);
        int pref=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            pref+=a[i];
        }

        bool possivel = false;
        if(pref>s) possivel = false;
        else{
            int dif=s-pref;
            possivel = (dif%x==0) ? true : false;
        }

        cout << (possivel ? "YES\n" : "NO\n");


    }
}