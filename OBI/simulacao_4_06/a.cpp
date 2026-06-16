#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int d;
    cin>>d;

    int nx,nd,sx,sd;
    cin >> nx >> nd >> sx >> sd;

    double tn=(d-nd)/(double)nx;
    double ts=(d-sd)/(double)sx;

    if(tn==ts) cout << "Empate\n";
    else if(tn<ts) cout << "Naruto\n";
    else cout << "Sasuke\n";
}