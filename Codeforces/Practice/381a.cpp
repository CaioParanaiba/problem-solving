#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long


void solve(){

    int n;
    cin >> n;

    deque<int> dq(n);
    for(int i=0;i<n;i++) cin >> dq[i];

    int s=0,d=0;

    bool st=true;
    while(dq.size()){
        if(dq.front()>dq.back()){
            if(st) {
                s+=dq.front();
                st=!st;
            }
            else{
                d+=dq.front();
                st=!st;
            }
            dq.pop_front();
        }
        else{
            if(st) {
                s+=dq.back();
                st=!st;
            }
            else{
                d+=dq.back();
                st=!st;
            }
            dq.pop_back();
        }
    }

    cout << s << " " << d << endl;
}

signed main(){
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}