#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m,c;
    cin >> n >> m >> c;
    map<int,int> pope;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        if(pope.find(a) != pope.end()) pope[a]++;
        else pope[a] = 1;
    }
    
    int somat=0;
    for(int i=0;i<m;i++)
    {
        double x = 0.5 + i;
        int somai = 0;
        while(somai<c)
        {
            int pessoas = pope[x+0.5];
            somai+=pessoas;
            x++;
            if(x>m) x = -0.5;
        }
        somat+=somai;
    }
    cout << somat << endl;

    return 0;
}