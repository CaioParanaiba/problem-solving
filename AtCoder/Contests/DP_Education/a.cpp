#include <bits/stdc++.h>
using namespace std;

#define ll long long

int Modulo(int x,int y)
{
  if(x<y) return y-x;
  else return x-y;
}

int main() {

  int n;
  cin >> n;

  vector<int> pedra(n);
  vector<int> custo(n,0);

  for(int i=0;i<n;i++)
  {
    cin >> pedra[i];
  }

  custo[1]=custo[0] + Modulo(pedra[0],pedra[1]);
  for(int i=2;i<n;i++)
  {
    int case1 = custo[i-1] + Modulo(pedra[i],pedra[i-1]);
    int case2 = custo[i-2] + Modulo(pedra[i],pedra[i-2]);

    if(case1<case2) custo[i]=case1;
    else custo[i] = case2;
  }

  cout << custo[n-1] << '\n';

  return 0;
}
