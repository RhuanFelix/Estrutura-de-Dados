/*
Implemente um programa em C que, a partir da lista simplesmente encadeada de números inteiros
l = {2, 6, 48, 26, 1, 7, 9, 0, 57, 10}, calcule a soma de seus elementos e informe tal resultado.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento * proximo;
} ELEMENTO;

typedef struct lista {
    ELEMENTO * inicio;
    int tamanho;
} LISTA;

LISTA * iniciar() {
    LISTA * l = (LISTA *)malloc(sizeof(LISTA));
    l->inicio = NULL;
    l->tamanho = 0;
    return l;
}

int empty(LISTA * l) {
    return l->tamanho == 0;
}

void add(LISTA * l, int numero) {
    if (empty(l)) {
        ELEMENTO * e = (ELEMENTO *)malloc(sizeof(ELEMENTO));
        e->valor = numero;
        e->proximo = NULL;
        l->inicio = e;
    } else {
        ELEMENTO * e = (ELEMENTO *)malloc(sizeof(ELEMENTO));
        e->valor = numero;
        ELEMENTO * antigo_inicio = l->inicio;
        l->inicio = e;
        e->proximo = antigo_inicio;
    }
    l->tamanho = l->tamanho + 1;
}

void somarValores(LISTA * l) {
    ELEMENTO * e = l->inicio;
    int soma = 0;
    while (e != NULL) {
        soma += e->valor;
        e = e->proximo;
    }
    printf("Soma: %d", soma);
}

int main () {
    LISTA * l = iniciar();

    add(l, 10);
    add(l, 57);
    add(l, 0);
    add(l, 9);
    add(l, 7);
    add(l, 1);
    add(l, 26);
    add(l, 48);
    add(l, 6);
    add(l, 2);

    somarValores(l);
}