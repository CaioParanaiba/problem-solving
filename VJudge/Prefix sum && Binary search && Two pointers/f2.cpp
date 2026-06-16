#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            int aa;
            cin >> aa;
            a[i].first;
            if(i>0 && a[i].)
        }

        int l=0,r=n-1;

        bool possivel=true;
        if(n==1 && a[0]!=1) possivel=false;
        while(l<=r && possivel){
            //cout << a[l] << " x " << r+1 << endl;
            if(a[l]!=r+1) possivel = false;
            l++;
            auto rit = upper_bound(a.rbegin(),a.rend(),a[r]);
            r = distance(rit,a.rend()) -1;
        }

        cout << (possivel ? "YES\n" : "NO\n");
    }
}