#include <bits/stdc++.h>

using namespace std;

double Distancia(pair<double, double> i1, pair<double, double> i2)
{
    return sqrt(pow(i1.first-i2.first,2)+pow(i1.second-i2.second,2));
}

void Ordenar(int*a,int*b)
{
    if(*a>*b)
    {
        int aux = *b;
        *b = *a;
        *a = aux;
    }
}

int main(){

    int n,p;
    cin >> n >> p;

    map<pair<int,int>,int> pos;
    vector<double> dist;

    int x1,y1;
    cin >> x1 >> y1;
    pos[{x1,y1}] = 1;
    for(int i=2;i<=n;i++)
    {
        int x2,y2;
        cin >> x2 >> y2;
        dist.push_back(Distancia({x1,y1},{x2,y2}));
        x1 = x2;
        y1 = y2;
        pos[{x1,y1}] = i;
    }

    for(int i=0;i<p;i++)
    {
        int x,y;
        cin >> x >> y;
        int a = pos[{x,y}];
        cin >> x >> y;
        int b = pos[{x,y}];
        Ordenar(&a,&b);
        double maior = 0;
        for(int j=(a-1);j<(b-1);j++)
        {
            if(maior<dist[j]) maior = dist[j];
        }
        cout << fixed << setprecision(2) << maior << endl;
    }



    return 0;
}