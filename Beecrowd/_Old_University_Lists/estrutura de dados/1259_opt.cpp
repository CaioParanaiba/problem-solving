#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<long long int> pares;
    vector<long long int> impares;
    for(int i=0;i<n;i++)
    {
        long long int num;
        cin >> num;
        if(num%2==0) pares.push_back(num);
        else impares.push_back(num);
    }

    sort(pares.begin(),pares.end(), [](auto& a, auto& b){
        return a < b;
    });

    sort(impares.begin(),impares.end(), [](auto& a, auto& b){
        return a > b;
    });    

    for(auto nu : pares)
    {
        cout << nu << endl;
    }

    for(auto nu : impares)
    {
        cout << nu << endl;
    }

    return 0;
}