#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'



signed main(){
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       vector<int> a(n);
       bool par=false,impar=false;
       for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]%2==0) par=true;
            else impar = true;
       }

       if(par && impar) sort(a.begin(),a.end());

       for(int i=0;i<n;i++){
            cout << a[i] << (i==n-1 ? '\n' : ' ');
       }
    }
}