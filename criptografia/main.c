#include <stdio.h>
#include <stdlib.h>

//desloca 3 caracteres para a direita
void primeiraPassada(char texto[1000]){
        for (int i = 0; i<1000; i++){
            if (texto[i] >= 65 && texto[i] <= 90 || texto[i] >= 97 && texto[i] <= 122){
                texto[i] = texto[i]+3;
                }
            }
}

//desloca 1 caractere para a esquerda
void terceiraPassada(char texto[1000]){
    int tamanho = strlen(texto)/2;
        for (int i = tamanho; i<strlen(texto); i++){
            texto[i] = texto[i]-1;
            }
}

int main()
{
    printf("Digite o texto para criptografar:\n");
    char texto [1000] = {};
    gets(texto);

    //P1: desloca 3 posições
    primeiraPassada(texto);

    //P2: inverte o texto
    strrev(texto);

    //P3: desloca para a esquerda
    terceiraPassada(texto);

    printf("Texto Criptografado: %s\n", texto);

 return 0;
}
