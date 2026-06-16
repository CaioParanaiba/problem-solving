#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m,d;
        cin >> n >> m >> d;
        vector<int> a(n+1);
        priority_queue<int,vector<int>,greater<int>> pq;

        int maior=0;

        int maior_at=0;
        for(int i=1;i<=n;i++){
            cin >> a[i];

            if(a[i]>0){
                pq.push(a[i]);
                maior_at+=a[i];
            }

            if(pq.size()>m){
                maior_at-=pq.top();
                pq.pop();
            }

            int maior1=maior_at-d*i;

            maior=max(maior,maior1);
        }
        cout << maior << '\n';
    }
}