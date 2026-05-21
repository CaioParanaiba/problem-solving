#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n,k,x;
    cin >> n >> k >> x;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(),a.end());

    int count=1;

    vector<int> diff;

    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>x){
            count++;
            diff.push_back(a[i]-a[i-1]);
        }
    }

    sort(diff.begin(),diff.end());

    for(int i=0;i<diff.size() && k;i++){
        int precisa = (diff[i]-1)/x;
        if(precisa>k) k=0;
        else{
            k-=precisa;
            count--;
        }
    }

    cout << count << '\n';
}