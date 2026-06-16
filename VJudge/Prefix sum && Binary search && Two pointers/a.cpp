#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];

        int a=0,b=n-1;
        int ta=v[a],tb=v[b],ans=0,cont=2;
        while(a!=b){
            if(ta==tb) ans=cont;

            if(ta>=tb){
                b--;
                tb+=v[b];
            }
            else{
                a++;
                ta+=v[a];
            }

            cont++;
        }

        cout << ans << endl;
    }   
}