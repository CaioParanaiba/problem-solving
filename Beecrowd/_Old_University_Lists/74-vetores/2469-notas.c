#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    int notas[n],freq[100];
    for(int i=0;i<100;i++)
    {
        freq[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d",&notas[i]);
        freq[notas[i]]++;
    }

    int maior_freq=0,numero_freq;
    for(int i=0;i<=100;i++)
    {
        if(freq[i]>=maior_freq)
        {
            maior_freq=freq[i];
            numero_freq=i;
        }
    }

    printf("%d\n",numero_freq);


    return 0;
}