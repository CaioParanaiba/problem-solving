#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> c(n);

        for(int i=0;i<n;i++) cin >> c[i];

        int a=0,b=0,ultimo=0;

        int l=0,r=n-1,moves=0;

        bool alicetime = false;

        while(l<=r){
            alicetime = !alicetime;
            int atual=0;
            moves++;

            if(alicetime){
                while(atual<=ultimo && l<=r){
                    atual+=c[l];
                    l++;
                }
                a+=atual;
            }
            else{
                while(atual<=ultimo && l<=r){
                    atual+=c[r];
                    r--;
                }
                b+=atual;
            }

            ultimo=atual;
        }

        cout << moves << ' ' << a << ' ' << b << '\n';
    }
}