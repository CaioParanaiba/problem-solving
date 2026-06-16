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
        for(int i=0;i<n;i++) cin >> a[i];

        int esq=-1;
        int dir=-1;
        bool troca=false;
        for(int i=0;i<n;i++){
            if(a[i]!=n-i && !troca){
                troca=true;
                esq=i;
            }
        }

        if(troca){
            troca=false;
            for(int i=esq;i<n;i++){
                if(a[i] == n- esq && !troca){
                    troca=true;
                    dir=i;
                }
            }

            reverse(a.begin()+esq,a.begin()+dir+1);
        }
        

        for(int i=0;i<n;i++){
            cout << a[i] << (i==n-1 ? '\n' : ' ');
        }

    }
}