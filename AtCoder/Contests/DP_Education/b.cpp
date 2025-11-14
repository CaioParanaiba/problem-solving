#include <bits/stdc++.h>
using namespace std;

#define ll long long

int Modulo(int x,int y)
{
  if(x<y) return y-x;
  else return x-y;
}

int PD(int at,int k,int n,vector<int>&pedra,vector<int>&custo)
{
  int menor = custo[at-1] + abs(pedra[at]-pedra[at-1]);
  for(int i=2;i<=k;i++)
  {
    if(at-i>=0)
    {

    int novo = custo[at-i] + abs(pedra[at]-pedra[at-i]);
    if(novo<menor) menor=novo;
    }
  }
  return menor;
}

int main() {

  int n,k;
  cin >> n >> k;

  vector<int> pedra(n);
  vector<int> custo(n,0);

  for(int i=0;i<n;i++)
  {
    cin >> pedra[i];
  }

  custo[0]=pedra[0];
  for(int i=1;i<n;i++)
  {
    custo[i] = PD(i,k,n,pedra,custo);
  }

  cout << custo[n-1] << '\n';

  return 0;
}

