/*
Crie um vetor de inteiros (int) de 10 posições. Preencha-o com os valores
10, 20, 30, 40, 50, 60, 70, 80, 90 e 100. Use um for para exibir os valores
deste vetor.
*/

#include <stdio.h>

#define TAM 10

int main(){
    int vetor[TAM] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for(int i = 0; i < TAM; i++){
        printf("%d\n", vetor[i]);
    }
    return 0;
}