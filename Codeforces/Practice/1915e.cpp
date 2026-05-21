#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int prefix=0;
        bool possivel=false;

        set<int> s;
        s.insert(0);

        for(int i=1;i<=n;i++){
            int a;
            cin >> a;
            prefix += (i%2==0) ? a : -a;
            
            if(s.count(prefix)) possivel=true;

            s.insert(prefix);
        }

        cout << (possivel ? "YES\n" : "NO\n");
    }
}