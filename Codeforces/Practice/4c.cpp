#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<string,int> r;

    while(n--){
        string s;
        cin >> s;

        
        if(r.contains(s)) {
            cout << s << r[s] << endl;
        }
        else cout  << "OK\n";
        r[s]++;

    }

}