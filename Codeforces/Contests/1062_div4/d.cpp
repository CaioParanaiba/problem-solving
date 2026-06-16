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
       for(int i=0;i<n;i++)cin >> a[i];

       int g = a[0];
       for(int i=1;i<n;i++){
        g = gcd(g,a[i]);
       }

       int x=2;
       while(gcd(g,x)!=1) x++;

       cout << x << endl;
    }
}