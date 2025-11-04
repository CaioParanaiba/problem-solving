#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,x;
    cin >> n >> x;

    int x1,x2;
    map<int,int> m;
    bool possivel = false;
    for(int i=1;i<=n;i++)
    {
        int xi;
        cin >> xi;
        int dif = x-xi;
        if(m.find(dif)!=m.end())
        {
            x1 = m[dif];
            x2 = i;
            possivel = true;
        }
        m[xi] = i;
    }

    if(possivel) cout << x1 << " " << x2 << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}