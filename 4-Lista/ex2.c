/*
Implemente um programa em C que utilize uma lista duplamente encadeada de caracteres para armazenar números
e verificar se são palíndromos. Dicas: os números podem ser fixos no código. Armazene-os separadamente na
lista. Use um vetor auxiliar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
    char valor;
    struct elemento * proximo;
    struct elemento * anterior;
} ELEMENTO;

typedef struct lista {
    ELEMENTO * inicio;
    ELEMENTO * elemento_corrente;
    int posicao_corrente;
    int tamanho;
} LISTA;

LISTA * iniciar() {
    LISTA * l = (LISTA *)malloc(sizeof(LISTA));
    l->inicio = NULL;
    l->elemento_corrente = NULL;
    l->tamanho = 0;
    l->posicao_corrente = 0;
    return l;
}

int empty(LISTA * l) {
    return l->tamanho == 0;
}

void add(LISTA * l, char caractere) {
    if (empty(l)) {
        ELEMENTO * e = (ELEMENTO *)malloc(sizeof(ELEMENTO));
        e->valor = caractere;
        e->proximo = NULL;
        e->anterior = NULL;
        l->inicio = e;
    } else {
        ELEMENTO * e = (ELEMENTO *)malloc(sizeof(ELEMENTO));
        ELEMENTO *antigo_inicio = l->inicio;
        e->valor = caractere;
        e->proximo = antigo_inicio;
        e->anterior = NULL;
        antigo_inicio->anterior = e;
        l->inicio = e;
    }
    l->tamanho = l->tamanho + 1;
}

char get(LISTA * l, int posicao) {
    if (empty(l)) {
        printf("Lista vazia!\n");
        return '\0';
    }

    if (posicao > l->tamanho || posicao <= 0) {
        printf("Posicao invalida!\n");
        return '\0';
    }

    if (l->elemento_corrente == NULL) {
        l->elemento_corrente = l->inicio;
        l->posicao_corrente = 1;
    }

    if (posicao == l->posicao_corrente) {
        return l->elemento_corrente->valor;
    } else {
        if (posicao > l->posicao_corrente) {
            int i = l->posicao_corrente;
            ELEMENTO * e = l->elemento_corrente;
            while (e != NULL) {
                if (i == posicao) {
                    l->elemento_corrente = e;
                    l->posicao_corrente = i;
                    return e->valor;
                } else {
                    e = e->proximo;
                    i++;
                }
            }
        }

        if (posicao < l->posicao_corrente) {
            int i = l->posicao_corrente;
            ELEMENTO * e = l->elemento_corrente;
            while (e != NULL) {
                if (i == posicao) {
                    l->elemento_corrente = e;
                    l->posicao_corrente = i;
                    return e->valor;
                } else {
                    e = e->anterior;
                    i--;
                }
            }
        }
    }

    return '\0';
}

int verificarPalindromo(LISTA * l) {
    char numeros[4];
    int j = 1;
    for (int i = 0; i < 3; i++) {
        numeros[i] = get(l, j);
        j++;
    }
    numeros[3] = '\0';
    
    j = 3;
    char numerosInvertidos[4];
    for (int i = 0; i < 3; i++) {
        numerosInvertidos[i] = get(l, j);
        j--;
    }
    numerosInvertidos[3] = '\0';
    return strcmp(numeros, numerosInvertidos); // 0 = são str iguais
}

int main () {
    LISTA * l1 = iniciar();
    LISTA * l2 = iniciar();

    add(l1, '2');
    add(l1, '5');
    add(l1, '3');

    printf("%d\n", verificarPalindromo(l1));

    add(l2, '3');
    add(l2, '9');
    add(l2, '3');

    printf("%d\n", verificarPalindromo(l2));
    return 0;
}