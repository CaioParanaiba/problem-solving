#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Competidor {
    int id;
    int r;
    int e;
    int fase;
};

int main(){

    int N;
    scanf("%d",&N);

    struct Competidor *placar_final = malloc(N * sizeof(struct Competidor));

    //Adicionar os jogares na lista
    for(int i=0; i<N; i++){
        int r_tempo,e_tempo;
        scanf("%d %d",&r_tempo,&e_tempo);

        placar_final[i].id = i+1;
        placar_final[i].r = r_tempo;
        placar_final[i].e = e_tempo;
        placar_final[i].fase = 1;

    }
    // dinir a frase e seu tamanho
    char *frase = malloc(100001 * sizeof(char));
    scanf("%s",frase);
    long long tamanho_frase = strlen(frase);

    //criar tabela_vivos
    struct Competidor *tabela_vivos = malloc(N * sizeof(struct Competidor));
    for(int i=0;i<N;i++){

        tabela_vivos[i] = placar_final[i];

    }
    
    int numero_vivos = N;


    while(numero_vivos>1){

        // Se não for a primeira fase, o texto dobra (FALTOU ESSA JOÇA)
        if (numero_vivos != N) {
            tamanho_frase *= 2;
        }

        //simulação 1 rodada
        struct Competidor *vencedores_fase = malloc(numero_vivos/2 * sizeof(struct Competidor));
        int k=0; //ordem na lista dos vencedores
        for(int i=0;i<numero_vivos;i+=2){
            
            // preciso de 64bits para garantir o tempo de cada jogador
            long long tempo_i = tabela_vivos[i].e * tamanho_frase + tabela_vivos[i].r;
            long long tempo_i_mais1 = tabela_vivos[i+1].e * tamanho_frase + tabela_vivos[i+1].r;

            if(tempo_i<tempo_i_mais1 || (tempo_i==tempo_i_mais1 && tabela_vivos[i].id<tabela_vivos[i+1].id)){
                vencedores_fase[k].id = tabela_vivos[i].id;
                vencedores_fase[k].r = tabela_vivos[i].r;
                vencedores_fase[k].e = tabela_vivos[i].e;
                vencedores_fase[k].fase = tabela_vivos[i].fase+1;
                
                int id_vencedor = tabela_vivos[i].id;
                int id_placar_final = id_vencedor-1;
                placar_final[id_placar_final].fase = tabela_vivos[i].fase+1;
            }
            else{
                vencedores_fase[k].id = tabela_vivos[i+1].id;
                vencedores_fase[k].r = tabela_vivos[i+1].r;
                vencedores_fase[k].e = tabela_vivos[i+1].e;
                vencedores_fase[k].fase = tabela_vivos[i+1].fase+1;
                
                int id_vencedor = tabela_vivos[i+1].id;
                int id_placar_final = id_vencedor-1;
                placar_final[id_placar_final].fase = tabela_vivos[i+1].fase+1;
            }
            k++;
        }

        // atualizar a tabela_vivos
        for(int i=0;i<k;i++){
            tabela_vivos[i] = vencedores_fase[i];
        }
        numero_vivos=k; // sobre k jogadores

        free(vencedores_fase); // Liberar a memória do array temporário a cada fase
    }
    printf("%d",placar_final[0].fase);
    for(int i=1;i<N;i++){
        printf(" %d",placar_final[i].fase);
    }
    printf("\n");

    free(placar_final);
    free(tabela_vivos);
    free(frase);

    return 0;
}


/*O que eu entendi desse problema:
--- Pontuação i VS i+1
Forma de ganhar = menor tempo = reação +escrita*caracteres
--- Participantes = n
--- EXEMPLO
4
n1 4 1
n2 3 1
n3 2 1
n4 1 1

eu entendi que o n2 ganha do n1 / n4 ganha n3
n3 ganha do n2
ficando
n1 1
n2 2
n3 1
n4 3


problema de tempo -> malloc?
*/




