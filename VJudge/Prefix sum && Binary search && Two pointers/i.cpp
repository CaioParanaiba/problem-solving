#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int,int>> a;

    int time=0;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        a.push_back({y,x});
    }

    sort(a.begin(),a.end());

    
    for(int l=0,r=a.size()-1;l<=r;){
        time = max(time,a[l].first+a[r].first);
        if(a[l].second<a[r].second){
            a[r].second-=a[l].second;
            l++;
        }
        else if(a[l].second>a[r].second){
            a[l].second-=a[r].second;
            r--;
        }
        else{
            l++;
            r--;
        }
    }
    
    cout << time << endl;
}