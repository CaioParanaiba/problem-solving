#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int pref=0,sum_k,times=0;
    unordered_map<int,int> m;
    m[0]=1;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;

        pref+=a;
        sum_k=pref-k;
        if(m.contains(sum_k)) times+=m[sum_k];

        m[pref]++;
    }

    cout << times << endl;
}