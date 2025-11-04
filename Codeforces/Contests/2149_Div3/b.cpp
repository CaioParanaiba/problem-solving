#include <iostream>

using namespace std;

void Ordem(int n,int * a)
{
    for(int k=0;k<n;k++)
    {
        int troca=0;
        for(int i=0;i<n;i++)
        {
            if(*(a+i)<*(a+k))
            {
                int aux = *(a+i);
                *(a+i) = *(a+k);
                *(a+k) = aux;
                troca++;
            }
        }
        if(troca==0) break;
    }
}

int main(){

    int t;
    cin >> t;
    for(int k=0;k<t;k++)
    {
        int n;
        cin >> n;
        int a[n];
        for(int l=0;l<n;l++)
        {
            scanf("%d",&a[l]);
        }

        Ordem(n,a);

        //vizualizar
        for(int l=0;l<n;l++) printf("%d ",a[l]);
        printf("\n");


        int bigger=0,dif;
        for(int l=0;l<(n-1);l=l+2)
        {
            dif = (a[l]-a[l+1]>0) ? a[l]-a[l+1] : a[l+1]-a[l];
            if(dif>bigger)
            {
                bigger=dif;
            }
        }

        cout << bigger << endl;

    }


    return 0;
}