#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];

    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int h;
        cin >> h;

        auto alta = upper_bound(a.begin(),a.end(),h);
        auto baixa = lower_bound(a.begin(),a.end(),h);

        if(baixa!=a.begin()){
            baixa--;
            cout << *baixa;
        }
        else cout << 'X';
        cout << ' ';
        if(alta!=a.end()) cout << *alta;
        else cout << 'X';
        cout << '\n';

    }
}