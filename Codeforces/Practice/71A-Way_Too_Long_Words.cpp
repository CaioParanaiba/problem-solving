#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        string word;
        cin >> word;
        int tamanho = word.length();
        if(tamanho<=10) cout << word << endl;
        else
        {
            char word0 = word[0], wordt = word[tamanho-1];

            tamanho-=2;

            cout << word0 << tamanho << wordt << endl;
        }
    }

    return 0;
}