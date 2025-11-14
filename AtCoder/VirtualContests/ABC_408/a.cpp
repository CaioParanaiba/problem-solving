#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n;
  double s;
  cin >> n>> s;

  s+=0.5;

  bool sleep = false;
  int lasttapped = 0;
  int time =0;
  for(int i=0;i<n;i++)
  {
    int tapped;
    cin >> tapped;
    time = tapped - lasttapped;
    //cout << time << endl;
    if(time >= s) sleep = true;
    lasttapped=tapped;
  }

  if(sleep) cout << "No\n";
  else cout << "Yes\n";

  return 0;
}
