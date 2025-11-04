#include <stdio.h>

int main(){

    int hh,mm;
    while(scanf("%d:%d",&hh,&mm)!=EOF)
    {

        for(int i=0;i<15;i++)
        {
            for(int j=0;j<48;j++)
            {
                //linha 0
                if(i==0 && j<44)
                {
                    if(j==0) printf(" ");
                    printf("_");
                }

                //lateral esquerda e direita
                if((j==0 && i!=0) || (j==45 && i!=0)) printf("|");

                //espaçamento inicial
                if((i==1 || i==13) && j>0) printf(" ");

                //linha 3
                if(i==2)
                {
                    if(j>0 && j<5)    printf(" ");
                    if(j>=5 && j<41)  printf("_");
                    if(j>=41 && j<45) printf(" ");
                    if(j==46)         printf("_");
                }

                //linha 4
                if(i==3)
                {
                    if(j>0 && j<4)    printf(" ");
                    if(j==4)          printf("|");
                    if(j>=5 && j<41)  printf(" ");
                    if(j==41)         printf("|");
                    if(j>41 && j<45)  printf(" ");
                    if(j==46)         printf("_");
                    if(j==47)         printf(")");
                }

                //linha 5
                if(i==4)
                {
                    if(j>0 && j<4)    printf(" ");
                    if(j==4)          printf("|");
                    if(j>4 && j<=7)   printf(" ");
                    if(j==8)          printf("8");
                    if(j>8 && j<=17)  printf(" ");
                    if(j==18)         printf("4");
                    if(j>18 && j<=27) printf(" ");
                    if(j==28)         printf("2");
                    if(j>28 && j<=37) printf(" ");
                    if(j==38)         printf("1");
                    if(j>38 && j<41)  printf(" ");
                    if(j==41)         printf("|");
                    if(j>41 && j<45)  printf(" ");
                }

                //linha 6 / 8 / 9 / 11
                if(i==5 || i==7 || i==8 || i==10)
                {
                    if(j>0 && j<4)    printf(" ");
                    if(j==4)          printf("|");
                    if(j>=5 && j<41)  printf(" ");
                    if(j==41)         printf("|");
                    if(j>41 && j<45)  printf(" ");
                }

                //linha 7 HORAS
                if(i==6)
                {
                    if(j>0 && j<4)    printf(" ");
                    if(j==4)          printf("|");
                    if(j>4 && j<=7)   printf(" ");
                    if(j==8)
                    {
                        if(hh>=8)
                        {
                            hh-=8;
                            printf("o");
                        }
                        else printf(" ");
                    }    
                    if(j>8 && j<=17)  printf(" ");
                    if(j==18)
                    {
                        if(hh>=4)
                        {
                            hh-=4;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>18 && j<=27) printf(" ");
                    if(j==28)
                    {
                        if(hh>=2)
                        {
                            hh-=2;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>28 && j<=37) printf(" ");
                    if(j==38)
                    {
                        if(hh>=1)
                        {
                            hh-=1;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>38 && j<41)  printf(" ");
                    if(j==41)         printf("|");
                    if(j>41 && j<45)  printf(" ");
                }

                //linha 10 MINUTOS
                if(i==9)
                {
                    if(j>0 && j<4)    printf(" ");
                    if(j==4)          printf("|");
                    if(j>4 && j<8)    printf(" ");
                    if(j==8)
                    {
                        if(mm>=32)
                        {
                            mm-=32;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>8 && j<14)   printf(" ");
                    if(j==14)
                    {
                        if(mm>=16)
                        {
                            mm-=16;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>14 && j<20)   printf(" ");
                    if(j==20)
                    {
                        if(mm>=8)
                        {
                            mm-=8;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>20 && j<26)   printf(" ");
                    if(j==26)
                    {
                        if(mm>=4)
                        {
                            mm-=4;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>26 && j<32)   printf(" ");
                    if(j==32)
                    {
                        if(mm>=2)
                        {
                            mm-=2;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>32 && j<38)   printf(" ");
                    if(j==38)
                    {
                        if(mm>=1)
                        {
                            mm-=1;
                            printf("o");
                        }
                        else printf(" ");
                    }
                    if(j>38 && j<41)  printf(" ");
                    if(j==41)         printf("|");
                    if(j>41 && j<45)  printf(" ");
                }

                //linha 12
                if(i==11)
                {
                    if(j>0 && j<4)    printf(" ");
                    if(j==4)          printf("|");
                    if(j>4 && j<8)    printf(" ");
                    if(j==9)         printf("32");
                    if(j>9 && j<14)   printf(" ");
                    if(j==15)         printf("16");
                    if(j>15 && j<20)  printf(" ");
                    if(j==20)         printf("8");
                    if(j>20 && j<26)  printf(" ");
                    if(j==26)         printf("4");
                    if(j>26 && j<32)  printf(" ");
                    if(j==32)         printf("2");
                    if(j>32 && j<38)  printf(" ");
                    if(j==38)         printf("1");
                    if(j>38 && j<41)  printf(" ");
                    if(j==41)         printf("|");
                    if(j>41 && j<45)  printf(" ");
                    if(j==45)         printf("_");
                }

                //linha 13
                if(i==12)
                {
                    if(j>0 && j<4)    printf(" ");
                    if(j==4)          printf("|");
                    if(j>=5 && j<41)  printf("_");
                    if(j==41)         printf("|");
                    if(j>41 && j<45)  printf(" ");
                    if(j==46)         printf("_");
                    if(j==47)         printf(")");
                }


                //ultima linha
                if(i==14 && j<44)
                {
                    printf("_");
                }
            }
            printf("\n");
        }

        printf("\n");

    }

    
    
    return 0;
}