#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

signed main(){
    int t;
    cin >> t;
    while(t--){
       bool ans=true;
       vector<int> freq(27,0);

       int n;
       cin >> n;
       for(int i=0;i<n;i++){
            char c;
            cin >> c;
            freq[c-'a']++;
       }
       for(int i=0;i<n;i++){
            char c;
            cin >> c;
            freq[c-'a']--;
       }

       for(int i=0;i<=26;i++){
            if(freq[i]!=0){
                i=27;
                ans=false;
            }
            //cout << i << ' ' << freq[i] << endl;
       }

       cout << (ans ? "YES\n" : "NO\n");
    }
}