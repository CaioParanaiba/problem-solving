#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

signed main(){
    int n,c;
    cin >> n >> c;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    map<int,int> m;
    for(int i=0;i<c;i++) {
        int nu,an;
        cin >> nu >> an;
        m[nu]=an;
    }
    int cont=0;
    for(int i=1;i<n;i++){
        if(a[i]<=a[i-1]) cont=1;
        else cont++;
        cout << cont;
        if(m.count(i)) a[i]+=m[i];
    }

}