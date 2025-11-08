#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

  int n,m,k;
  cin >> n >> m >> k;

  deque<int> h;
  deque<int> b;

  for(int i=0;i<n;i++)
  {
    int hi;
    cin >> hi;

    h.push_back(hi);
  }
  sort(h.begin(),h.end());

  for(int i=0;i<m;i++)
  {
    int bi;
    cin >> bi;

    b.push_back(bi);
  }
  sort(b.begin(),b.end());

  //for(auto ii : h)
  //{
  //  cout << ii << " ";
  //}
  //cout << endl;
  //for(auto ii : b)
  //{
  //  cout << ii << " ";
  //}

  int kt=0;
  while(!b.empty())
  {
    //cout << "H: " << h.front() << " B: " << b.front() << endl;

    if(kt==k)
    {
      break;
    }

    if(h.front()<=b.front())
    {
      //cout << "Anterior JUntou! " << endl;
      b.pop_front();
      h.pop_front();
      kt++;
    }
    else
    {
      //cout << "Cabeca MAIOR aumenta o corpo" << endl;
      b.pop_front();
    }
  }

  if(kt==k) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

