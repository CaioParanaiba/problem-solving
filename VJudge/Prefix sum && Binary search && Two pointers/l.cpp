#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q,t=1;
    cin >> n >> q;
    while(n!=0 || q!=0){
        printf("CASE# %d:\n",t);
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        sort(a.begin(),a.end());

        for(int i=1;i<=q;i++){
            int x;
            bool possivel = true;
            cin >> x;
            cout << x;
            auto it = lower_bound(a.begin(),a.end(),x);
            if(it==a.end() || *it!=x) possivel=false;

            if(!possivel) cout << " not found\n";
            else cout << " found at " << it-a.begin() +1<< '\n';
        }

        cin >> n >> q;
        t++;
    }
}