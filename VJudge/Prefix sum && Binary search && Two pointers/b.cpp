#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,s,s0=0;
        cin >> n >> s;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }

        int tamanho = -1;
        int esq=0;

        for(int dir=0;dir<n;dir++){
            s0+=a[dir];

            while(s0>s && esq<dir){
                s0-=a[esq];
                esq++;
            }

            if(s==s0) tamanho = max(tamanho,dir-esq+1);
        }

        
        cout << (tamanho!=-1 ? n-tamanho : tamanho) << endl;

    }
}