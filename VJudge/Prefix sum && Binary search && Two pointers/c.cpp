#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second=i;
    }

    sort(a.begin(),a.end());
    
    int l=0,r=n-1;

    bool possivel = false;
    for(int i=0;i<n-3 && !possivel;i++){
        for(int j=i+1;j<n-2 && !possivel;j++){
            int v = k - a[i].first - a[j].first;

            int l=j+1,r=n-1;
            while(l<r && !possivel){
                int soma = a[l].first + a[r].first;
                if(soma==v){
                    possivel=true;
                    cout << a[i].second+1 << ' ' << a[j].second+1 << ' ' << a[l].second+1 << ' ' << a[r].second+1 << '\n';
                }
                else if(soma>v) r--;
                else l++;
            }
        }
    }

    if(!possivel) cout << "IMPOSSIBLE\n";
}