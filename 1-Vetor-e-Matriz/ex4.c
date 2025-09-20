/*
Faça um programa com uma matriz com 9 elementos (3x3) reais positivos
(aleatórios e de sua escolha). Calcule e exiba a soma dos elementos de cada linha desta matriz.
*/

#include <stdio.h>

int main(){
    float matriz[3][3] = {
        {1, 2.5, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    float soma = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            soma += matriz[i][j];
        }
    }
    printf("Soma: %.2f", soma);
    return 0;
}