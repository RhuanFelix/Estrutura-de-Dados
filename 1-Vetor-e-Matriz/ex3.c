/*
Faça um programa com um vetor com 10 elementos inteiros positivos
(aleatórios e de sua escolha). Permita que seja solicitado um determinado
valor inteiro e positivo para ser procurado neste vetor. Caso exista,
o programa deve exibir o índice no qual o valor está posicionado. Caso
contrário, o programa deve informar que o elemento não existe no vetor.
*/

#include <stdio.h>

int main(){
    int vetor[10] = {2, 7, 4, 10, 40, 23, 11, 32, 92, 100};
    int valor;
    int valorEncontrado = 0;
    printf("Insira um valor: ");
    scanf("%d", &valor);
    if(valor >= 0){
        for(int i = 0; i < 10; i++){
            if(valor == vetor[i]){
                printf("O valor %d esta posicionado no indice %d do vetor\n", valor, i);
                valorEncontrado = 1;
                break;
            }
        }
        if(valorEncontrado == 0){
            printf("O valor informado nao existe no vetor\n");
        }
    } else{
        printf("E necessario colocar um valor positivo\n");
    }
    return 0;
}