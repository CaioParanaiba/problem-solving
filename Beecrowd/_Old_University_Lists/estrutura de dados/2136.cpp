#include <bits/stdc++.h>

using namespace std;

int main(){

    string name;
    map<string, int> yes;
    map<string, int> no;

    int y=0,n=0;
    while((cin >> name) && name!="FIM")
    {
        string voto;
        cin >> voto;

        if(voto=="YES")
        {
            if(yes.find(name)==yes.end()) yes[name]=y;
            y++;
        }
        else
        {
            no[name]=n;
            n++;
        }
    }

    int cont_char=0;
    string amigo;
    for(auto& pair : yes)
    {
        cout << pair.first << endl;
        if(cont_char<pair.first.size())
        {
            amigo = pair.first;
            cont_char = pair.first.size();
        }
        else if(cont_char==pair.first.size())
        {
            if(yes[amigo]>pair.second)
            {
                amigo = pair.first;
                cont_char=pair.first.size();
            }
        }

    }
    for(auto& pair : no)
    {
        cout << pair.first << endl;
    }

    cout << "\nAmigo do Habay:\n" << amigo << endl;

    return 0;
}