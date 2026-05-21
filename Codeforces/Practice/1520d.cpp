#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        map<int,int> a;
        int count=0;

        for(int i=0;i<n;i++) {
            int valor;
            cin >> valor;
            valor = valor - i;
            
            count+=a[valor];

            a[valor]++;
        }

        cout << count << '\n';

    }
}