#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,a,b;
    cin >> n >> m >> a >> b;

    int custa = a*n;
    int custb = (n/m)*b + min((n%m)*a,b);

    cout << min(custa,custb) << '\n';

}