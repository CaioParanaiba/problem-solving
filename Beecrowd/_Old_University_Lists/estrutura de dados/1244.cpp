#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    cin.ignore();

    for(int i=0;i<n;i++)
    {

        string frase;
        getline(cin, frase);

        istringstream iss(frase);

        string palavra;

        vector<string> orde_palavra;

        int maior = 0;
        while(iss >> palavra)
        {
            orde_palavra.push_back(palavra);
            if(maior<palavra.size()) maior = palavra.size();
        }

        stable_sort(orde_palavra.begin(),orde_palavra.end(), [](auto& a, auto& b){
            return a.size() > b.size();
        });

        string separador = "";
        for(auto& p : orde_palavra)
        {
            cout << separador << p;
            separador = " ";
        }

        cout << endl;
    }

    return 0;
}