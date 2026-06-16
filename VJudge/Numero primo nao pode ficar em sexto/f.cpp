#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;
    
    int ans=0;
    for(int i=2;i*i<=n;i++){
        //cout << "valor i: " << i << endl;
        if(n%i==0){
            int potencia=0;
            while(n%i==0){
                potencia++;
                n/=i;
            }

            int atual=1;
            while(potencia>=atual){
                ans++;
                potencia-=atual;
                atual++;
            }
        }
    }
    if(n>1) ans++;

    cout << ans << endl;
}