#include <stdio.h>
#include <string.h>

struct Competidor {
    int id;
    int r;
    int e;
    int fase;
};

int main(){

    int N;
    scanf("%d",&N);

    struct Competidor placar_final[N];

    //Adicionar os jogares na lista
    for(int i=0; i<N; i++){
        int r_tempo,e_tempo;
        scanf("%d %d",&r_tempo,&e_tempo);

        placar_final[i].id = i+1;
        placar_final[i].r = r_tempo;
        placar_final[i].e = e_tempo;
        placar_final[i].fase = 1;
    }

    // Definir a frase e seu tamanho
    char frase[100001]; // Aumentado para 100001 para comportar o '\0'
    scanf("%s",frase);
    long long tamanho_frase = strlen(frase); // Usar long long para evitar overflow em fases avançadas

    //criar tabela_vivos
    struct Competidor tabela_vivos[N];
    for(int i=0;i<N;i++){
        tabela_vivos[i] = placar_final[i];
    }
    
    int numero_vivos = N;
    int fase_atual = 1;

    while(numero_vivos>1){
        
        // Se não for a primeira fase, o texto dobra
        if (fase_atual > 1) {
            tamanho_frase *= 2; // <-- CORREÇÃO PRINCIPAL
        }

        //simulação 1 rodada
        struct Competidor vencedores_fase[numero_vivos/2];
        int k=0; //ordem na lista dos vencedores
        for(int i=0;i<numero_vivos - (numero_vivos % 2);i+=2){
            
            // preciso de 64bits para garantir o tempo de cada jogador
            long long tempo_i = (long long)tabela_vivos[i].e * tamanho_frase + tabela_vivos[i].r;
            long long tempo_i_mais1 = (long long)tabela_vivos[i+1].e * tamanho_frase + tabela_vivos[i+1].r;

            int id_vencedor;
            if(tempo_i < tempo_i_mais1 || (tempo_i == tempo_i_mais1 && tabela_vivos[i].id < tabela_vivos[i+1].id)){
                vencedores_fase[k] = tabela_vivos[i];
                id_vencedor = tabela_vivos[i].id;
            }
            else{
                vencedores_fase[k] = tabela_vivos[i+1];
                id_vencedor = tabela_vivos[i+1].id;
            }
            
            vencedores_fase[k].fase++;
            placar_final[id_vencedor - 1].fase++;
            k++;
        }

        // atualizar a tabela_vivos
        for(int i=0;i<k;i++){
            tabela_vivos[i] = vencedores_fase[i];
        }
        numero_vivos=k; // sobre k jogadores
        fase_atual++;
    }

    printf("%d",placar_final[0].fase);
    for(int i=1;i<N;i++){
        printf(" %d",placar_final[i].fase);
    }
    printf("\n");

    return 0;
}