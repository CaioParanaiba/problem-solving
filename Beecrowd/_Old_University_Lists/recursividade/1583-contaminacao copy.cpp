#include <iostream>

using namespace std;

int main()
{

    int n,m;
    cin >> n >> m;
    while(n!=0 || m!=0)
    {
        //n+=2;
        //m+=2;
        char mapa[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //if(j==0 || j==(m-1)) mapa[i][j] = 'X';
                //else if(i==0 || i ==(n-1)) mapa[i][j]= 'X';
                //else cin >> mapa[i][j];
                cin >> mapa[i][j];
                cout << mapa[i][j];
            }
        }


        


    }

    return 0;
}