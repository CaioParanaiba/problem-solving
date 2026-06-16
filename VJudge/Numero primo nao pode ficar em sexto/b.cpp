#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n=100000001;
    vector<bool> primos(n,1);primos[1]=false;

    int k=0;
    for(int p=2;p<n;p++){
        if(!primos[p]) continue;
        if(k%100==0)cout << p << '\n';
        k++;
        for(int i=p*p;i<n;i+=p){
            primos[i]=false;
        }
    }
}