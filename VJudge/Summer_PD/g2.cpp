#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int pd[2];

    pd[0]=0;
    pd[1]=-1e9;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;

        cout << "\nEscolhas:\n";
        cout << "pd0: " << pd[0] << " pd1: " <<pd[1] <<endl;
        cout << "pd0+y: " << pd[0]+y << "pd1+y: " << pd[1]+y << endl;

        if(x==1){
            pd[1] = max(pd[0]+y,pd[1]);
        }
        else{
            pd[0] = max({pd[0],pd[0]+y,pd[1]+y});
        }
    }

    cout << max(pd[0],pd[1]) << endl;
}