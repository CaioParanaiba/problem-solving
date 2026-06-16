#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

signed main(){
    int t;
    cin >> t;
    while(t--){
        //cout << endl;
        vector<int> c(3);
        unordered_map<int,char> m = {{0,'R'},{1,'G'},{2,'B'}};
        for(int i=0;i<3;i++) cin >> c[i];


        //int k=0;
        bool iguais=false;
        if(c[0]==c[1] && c[1]==c[2]){
            for(int i=0;i<c[0];i++){
                cout << m[0] << m[1] << m[2];
            }
            iguais=true;
        }
        while((c[0]!=0 || c[1]!=0 || c[2]!=0) && !iguais){
            //cout << "\nRodada " << k << ": " << c[0] << ' ' << c[1] << ' ' << c[2] << endl;
            int m1,m2,maior1=-1,maior2=-1;
            for(int i=0;i<3;i++){
                if(maior1<c[i]){
                    m2=m1;
                    maior2=maior1;
                    m1=i;
                    maior1=c[i];
                    
                }
                else if(maior2<c[i]){
                    m2=i;
                    maior2=c[i];
                }
            }

            //cout << "Maior: " << m1 << " Segundo: " << m2 << " valores maior: " << maior1 << " outro: " << maior2 << endl;

            if(!c[m2]){
                cout << m[m1];
                c[m1]=0;
            }
            else{
                while(c[m2]){
                    cout << m[m1] << m[m2];
                    c[m1]--;
                    c[m2]--;
                }
            }
            //k++;

        }
        cout << endl;

    }
}