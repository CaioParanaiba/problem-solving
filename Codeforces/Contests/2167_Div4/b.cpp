#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        vector<char> palavra1;
        for(int j=0;j<n;j++)
        {
            char c;
            cin >> c;
            palavra1.push_back(c);         
        }
        vector<char> palavra2;
        for(int j=0;j<n;j++)
        {
            char c;
            cin >> c;
            palavra2.push_back(c);         
        }
        sort(palavra1.begin(),palavra1.end());
        sort(palavra2.begin(),palavra2.end());
        bool iguais = true;
        for(int j=0;j<n;j++)
        {
            if(palavra1[j]!=palavra2[j]) iguais = false;
        }
        if(iguais) cout << "YES" << endl;
        else cout << "NO" << endl;
    
    }

    return 0;
}