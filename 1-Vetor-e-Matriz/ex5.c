/*
Faça um programa com uma matriz 5x5 de inteiros positivos ou negativos
(aleatórios e de sua escolha) e encontre e exiba o maior elemento desta matriz;
*/

#include <stdio.h>

int main(){
    int matriz[5][5] = {
        {-3, 9, 0, 1, 7},
        {10, -20, 12, -2, -100},
        {2, 20, -1, 22, 21},
        {3, 4, 5, 6, 7},
        {8, 11, -45, -223, 19},
    };
    int maior = matriz[0][0];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }
    printf("O maior elemento da matriz e: %d", maior);
    return 0;
}