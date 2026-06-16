#include <bits/stdc++.h>

using namespace std;

int main(){
    double d,h,v,e;
    cin >> d >> h >> v >>e;

    double pi = 3.1415926535;

    d=d/2;

    double area=(double)pi*(d*d);

    double vv = (double)v/area;

    //cout << e << ' ' << vv << endl;

    if(e>=vv) cout << "NO\n";
    else{
        double t=(double)h/(vv-e);
        if(t<10000){
            cout << "YES\n";
            printf("%.8lf\n",t);
        }
        else cout << "NO\n";
    }
}