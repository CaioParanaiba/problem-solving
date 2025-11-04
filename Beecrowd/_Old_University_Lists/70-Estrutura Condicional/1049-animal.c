#include <stdio.h>
#include <string.h>

int main(){

    char c1[20],c2[20],c3[20];
    scanf("%s %s %s",&c1,&c2,&c3);
    if(strcmp(c1,"vertebrado")==0){
        if(strcmp(c2,"ave")==0){
            if(strcmp(c3,"carnivoro")==0){
                printf("aguia\n");
            }
            else if(strcmp(c3,"onivoro")==0){
                printf("pomba\n");
            }
        }
        else if(strcmp(c2,"mamifero")==0){
            if(strcmp(c3,"onivoro")==0){
                printf("homem\n");
            }
            else if(strcmp(c3,"herbivoro")==0){
                printf("vaca\n");
            }
        }
    }
    else if(strcmp(c1,"invertebrado")==0){
        if(strcmp(c2,"inseto")==0){
            if(strcmp(c3,"hematofago")==0){
                printf("pulga\n");
            }
            else if(strcmp(c3,"herbivoro")==0){
                printf("lagarta\n");
            }
        }
        else if(strcmp(c2,"anelideo")==0){
            if(strcmp(c3,"hematofago")==0){
                printf("sanguessuga\n");
            }
            else if(strcmp(c3,"onivoro")==0){
                printf("minhoca\n");
            }
        }
    }

    return 0;
}