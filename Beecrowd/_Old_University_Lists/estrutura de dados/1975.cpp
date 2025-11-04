#include <bits/stdc++.h>

using namespace std;

int Verfi(vector<string> perolas,string p)
{
    for(int i=0;i<perolas.size();i++)
    {
        if(perolas[i]==p) return 1;
    }
    return 0;
}

int main(){

    //LOOP MAIOR DE P A R NÃO ESQUECER
    int P, A, R;
    while((cin >> P >> A >> R) && R!=0)
    {
        cin.ignore();

        set<string> perolas;
        for(int i=0;i<P;i++)
        {
            string p;
            getline(cin,p);
            perolas.insert(p);
        }

        map<string, int> alunos;
        int maior_num=0;
        for(int i=0;i<A;i++)
        {        
            string name;
            cin >> name;

            cin.ignore();

            int num_p=0;
            for(int j=0;j<R;j++)
            {
                string p;
                getline(cin,p);
                if(perolas.count(p)) num_p++;
            }
            if(maior_num<num_p) maior_num = num_p;
            alunos[name] = num_p;
        }

        vector<string> alunos_p;
        for(auto pair : alunos)
        {
            if(pair.second==maior_num) alunos_p.push_back(pair.first);
        }

        for(int i=0;i<alunos_p.size();i++)
        {
            cout << alunos_p[i];
            if(i<alunos_p.size()-1) cout << ", ";
        }
        cout << endl;
    }

    return 0;
}