#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<long long int> numeros;
    for(int i=0;i<n;i++)
    {
        long long int num;
        cin >> num;
        numeros.push_back(num);
    }

    sort(numeros.begin(),numeros.end(), [](auto& a,auto& b)
    {
        if((a%2) != (b%2))
        {
            return a%2==0;
        }

        else
        {
            //iguais
            if(a%2==0) return a < b;
            else return a > b;
        }
    });

    for(auto nu : numeros)
    {
        cout << nu << endl;
    }

    return 0;
}