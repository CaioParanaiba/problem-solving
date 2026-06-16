#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<bool> primos(1000001,1);primos[1]=false;
    vector<int> maiorp(1000001);

    for(int p=2;p<primos.size();p++){
        if(!primos[p]) continue;
        for(int i=p*2;i<=primos.size();i+=p){
            primos[i]=false;
            maiorp[i]=p;
        }
    }
}