#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;
    
    map<string,string> comand;
    for(int i=0;i<n;i++)
    {
        string name,ip;
        cin >> name >> ip;
        cin.ignore();

        comand[ip] = name;
    }

    for(int i=0;i<m;i++)
    {
        string server,ip;
        cin >> server >> ip;

        string ip_antigo = ip;
        ip.pop_back();

        cout << server << " " << ip_antigo << " #" << comand[ip] << endl;
    }

    return 0;
}