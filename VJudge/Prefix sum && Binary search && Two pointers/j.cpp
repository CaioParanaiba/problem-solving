#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    vector<vector<int>> id(3,vector<int>(n+1));
    id[0][0]=0;id[1][0]=0;id[2][0]=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        
        id[0][i+1] = id[0][i];
        id[1][i+1] = id[1][i];
        id[2][i+1] = id[2][i];

        if(a[i] == 1) id[0][i+1]++;
        else if(a[i] == 2) id[1][i+1]++;
        else if(a[i] == 3) id[2][i+1]++;
    }

    
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        int r1 = id[0][r] - id[0][l-1];
        int r2 = id[1][r] - id[1][l-1];
        int r3 = id[2][r] - id[2][l-1];
        
        cout << r1 << ' ' << r2 << ' ' << r3 << '\n';

        
    }
}