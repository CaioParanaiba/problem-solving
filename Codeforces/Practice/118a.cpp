#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long


void solve(){

    string s;
    cin >> s;

    stack<char> st;

    for(int i=s.size()-1;i>=0;i--){
        char c = tolower(s[i]);
        if(c!='a' && c!='o' && c!='y' && c!='e' && c!='u' && c!='i') {
            st.push(c);
            st.push('.');
        }
    }

    while(st.size()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

signed main(){
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}