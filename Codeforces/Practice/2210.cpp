#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> a(n),b(n);

        cin >> a[0];
        int ga = a[0];
        for(int i=1;i<n;i++){
            cin >> a[i];
            ga = gcd(ga,a[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            cin >> b[i];
            if(ga<=b[i] && ga!=a[i]) ans++;
        }

        cout << ga << ' ' << ans << endl;
    }
}