/*
Implemente um programa em C que utilize uma lista simplesmente encadeada de números inteiros e que não permita
que números repetidos sejam adicionados. Dica: solicite os valores a serem adicionados.
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

int adicionarSemRepetir(LISTA * l) {
    int valor;
    printf("Informe um valor para adicionar na lista: ");
    scanf("%d", &valor);
    ELEMENTO * e = l->inicio;
    if (!empty(l)) {
        while (e != NULL) {
            if (e->valor == valor) {
                printf("Este valor ja esta na lista, nao pode ser inserido!\n");
                return 0;
            }
            e = e->proximo;
        }
    }

    add(l, valor);

    return 1;
}

int main () {
    LISTA * l = iniciar();
    int qtdValoresNaLista;
    printf("Digite quantos valores voce quer incluir na lista: ");
    scanf("%d", &qtdValoresNaLista);

    for (int i = 0; i < qtdValoresNaLista; i++) {
        if (adicionarSemRepetir(l) == 0) {
            i--;
        }
    }

    ELEMENTO * e = l->inicio;
    while (e != NULL) {
        printf("%d ", e->valor);
        e = e->proximo;
    }
    
    return 0;
}