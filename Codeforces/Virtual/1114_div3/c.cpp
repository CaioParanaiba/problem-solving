#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        string ans;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]) ans+=s[i];
            else continue;
        }
        ans+=s[n-1];

        int maxreducao=0;
        for(int i=1;i<n-1;i++){
            int reducao=0;

            if(s[i-1]==s[i]  || s[i]==s[i+1]) reducao=0;
            else if(s[i-1]==s[i+1]) reducao=2;
            else reducao=1;

            maxreducao=max(maxreducao,reducao);
        }

        cout << ans.size()-maxreducao << endl;
    }
}