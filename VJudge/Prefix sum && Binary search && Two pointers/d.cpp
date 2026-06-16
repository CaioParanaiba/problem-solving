#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second=i;
    }

    sort(a.begin(),a.end());

    bool possivel = false;
    for(int i=0;i<n-2 && !possivel;i++){
        int v=x-a[i].first;
        int l=i+1,r=n-1;
        while(l<r && v>1 && !possivel){
            int soma=a[l].first+a[r].first;

            if(soma==v){
                cout << a[i].second+1 << ' ' << a[l].second+1 << ' ' << a[r].second+1 << '\n';
                possivel=true;
            }
            else if(soma>v) r--;
            else l++;
        }
    }

    if(!possivel) cout << "IMPOSSIBLE\n";
}