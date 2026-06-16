#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    string original = "abcdefghijklmnopqrstuvwxyz";
    string cifra;
    cin >> cifra;

    map<char,char> mp;
    for(int i=0;i<26;i++){
        mp[cifra[i]]=original[i];
    }

    string frase;
    cin >> frase;
    string pira="pirata";
    string capi="capita";
    int pp=0,cc=0;
    for(int i=0;i<frase.size();i++){
        frase[i]=mp[frase[i]];
        if (pp < 6 && frase[i] == pira[pp]) pp++;
        if (cc < 6 && frase[i] == capi[cc]) cc++;
    }

    if(pp==6  && cc==6) cout << "adulterada\n";
    else if(pp==6) cout << "falsa\n";
    else if(cc==6) cout << "original\n";
    else cout << "quemestaai?\n";

}