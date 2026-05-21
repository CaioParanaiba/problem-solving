#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string r,s;
        cin >> s;

        r+=s[0];
        for(int i=1;i<s.size();i++){
           if(s[i]!=r[i-1]){
            char aux = r[i-1];
            r[i-1]=s[i];
            r+=aux;
           }
           else r+=s[i];
        }

        if(s==r) cout << "NO" << endl;
        else{
            cout << "YES\n" << r << endl;
        }
    }
}