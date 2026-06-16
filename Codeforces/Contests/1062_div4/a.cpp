#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

signed main(){
    int t;
    cin >> t;
    while(t--){
        bool possivel = true;
        int a;
        cin >> a;
        for(int i=1;i<4;i++){
            int b;
            cin >> b;
            if(a!=b) possivel=false;
            a=b;
        }

        cout << (possivel ? "YES\n" : "NO\n");
    }
}