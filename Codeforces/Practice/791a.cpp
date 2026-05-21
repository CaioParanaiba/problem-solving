#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
 
    int d=0;
    while(a<=b){
        a*=3;
        b*=2;
        d++;
    }

    cout << d << endl;
    
}