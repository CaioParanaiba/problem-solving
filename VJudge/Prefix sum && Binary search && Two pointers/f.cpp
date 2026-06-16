#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> freq(n+1,0),a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]<=n) freq[a[i]]++;
        }

        for(int i=n-1;i>0;i--){
            freq[i]+=freq[i+1];
        }

        bool possivel = true;
        for(int i=0;i<=n/2;i++){
            if(a[i]!=freq[i+1]) possivel = false;
        }

        cout << (possivel ? "YES\n" : "NO\n");
    }
}