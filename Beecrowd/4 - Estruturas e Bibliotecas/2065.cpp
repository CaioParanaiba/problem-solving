#include <bits/stdc++.h>
using namespace std;

#define ll long long

void Ordena(vector<pair<int,int>>&fila)
{
  sort(fila.begin(),fila.end(), [](auto&a,auto&b){
    if(a.first<b.first) return true;
    else if(a.first==b.first && a.second<b.second) return true;
    else return false;
  });
}

int main() {

  int f,c;
  cin >> f >> c;

  vector<int> velocidade(f);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> fila;

  for(int i=0;i<f;i++)
  {
    int v;
    cin >> v;
    
    velocidade[i]=v;
    fila.push({0,i});
  }

  int maior_tempo = 0;
  for(int i=0;i<c;i++)
  {
    int valor;
    cin >> valor;

    auto[t,id] = fila.top();
    fila.pop();

    t+=valor*velocidade[id];
    fila.push({t,id});
    //Ordena(fila);
    if(maior_tempo<t) maior_tempo = t;
    //cout << t << ' ' << v << endl;
  }

  cout << maior_tempo << '\n';


  return 0;
}
