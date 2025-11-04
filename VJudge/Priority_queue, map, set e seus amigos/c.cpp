#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    map<string,int> repete;
    for(int i=0;i<n;i++)
    {
        string palavra;
        cin >> palavra;

        if(repete.find(palavra)==repete.end())
        {
            cout << "OK" << endl;
            repete[palavra] = 1;
        }
        else
        {
            cout << palavra << repete[palavra] << endl;
            repete[palavra]++;
        }
    }

    return 0;
}