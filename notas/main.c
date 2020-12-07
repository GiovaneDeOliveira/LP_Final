#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5 //numero de alunos
#define A 6 //numero de questões+1

struct candidato{
    int numCandidatos;
    char respostaCandidato [A];
    int nota;
};

int main()
{
    int i=0;
    int ranking [N][2] = {0};
    struct candidato can [N];
    char gabarito[A] = {'\0'};
    registrarGabarito(gabarito); //solicita e salva o gabarito oficial
    gravarCandidatosERespostas(can, ranking, gabarito); //grava os candidatos e respostas
    reorganizarRanking(ranking); //organiza o ranking em ordem decrescente
    imprimirRanking(ranking); //imprime o ranking
    return 0;
}

//solicita e salva o gabarito
void registrarGabarito(char gabarito[A]){
    printf("Digite o gabarito oficial:\n");
    scanf("%s", gabarito);
    //printf("\n%s", gabarito);
}

//salva a matrícula e respostas dos candidatos
void gravarCandidatosERespostas(struct candidato can[N], int ranking[N][2], char gabarito[A]){
    int i;
    for(i=0; i<N; i++){
            printf("Digite o numero do candidato:\n");
            scanf("%d", &can[i].numCandidatos);

            printf("Digite as respostas do candidato %d:\n", can[i].numCandidatos);
            scanf("%s", can[i].respostaCandidato);
            int j = 0;
            calcularNota(i, can, ranking, gabarito); //chama a função calcularNota
        }
}

//calcula a nota do candidato e salva no ranking e na estrutura do candidato
void calcularNota(int i, struct candidato can[N], int ranking[N][2], char gabarito[51]){
    int j =0;
    can[i].nota = 0;
    for (j; j<(A-1); j++){
                if (gabarito[j] == can[i].respostaCandidato[j]) {
                    can[i].nota = can[i].nota+1;
                }
            }
    ranking[i][0] = can[i].numCandidatos;
    ranking[i][1] = can[i].nota;
}

//reorganiza o ranking
void reorganizarRanking(int ranking[N][2]){

    int k =0;
    int m =0;
    int temp =0;
        for(k=0; k<N; k++){
            for(m=k; m<N; m++){
                if(ranking [m][1]> ranking [k][1]){
                    temp = ranking [m][1];
                    ranking [m][1] = ranking [k][1];
                    ranking [k][1] = temp;
                    temp = ranking [m][0];
                    ranking [m][0] = ranking [k][0];
                    ranking [k][0] = temp;
                }
            }
        }
}

//imprime o ranking
void imprimirRanking(int ranking[N][2]){
    int k=0;
    for(k=0; k<N; k++){
        printf("\n%d %d",ranking[k][0],ranking[k][1]);
    }
}

