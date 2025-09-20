/*
Escreva uma função em C que recebe duas filas, "f1" e "f2", ambas contendo números inteiros.
Os elementos dessas filas apresentam-se em ordem crescente, ou seja, o menor valor de cada
fila encontra-se no início dela. A partir delas, crie uma terceira fila de números inteiros
também em ordem crescente formada pelos elementos que se encontram nas filas "f1" e "f2".
Por exemplo, se f1 = {2, 10, 15, 25}, onde 2 é o início da fila, e f2 = {3, 5, 9, 15}, onde
3 é o início, a fila "f3" construída deve ser {2, 3, 5, 9, 10, 15, 15, 25}, onde 2 é o início
e 25 é o fim da fila.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento * proximo;
} ELEMENTO;

typedef struct fila {
    ELEMENTO * cabeca;
    ELEMENTO * fim;
    int tamanho;
} FILA;

FILA * iniciar() {
    FILA * f = (FILA *)malloc(sizeof(FILA));
    f->cabeca = NULL;
    f->fim = NULL;
    f ->tamanho = 0;
    return f;
}

void enqueue(FILA * f, int valor) {
    ELEMENTO * e = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    e->valor = valor;
    e->proximo = NULL;

    if (f->fim != NULL) {
        f->fim->proximo = e;
    } else {
        f->cabeca = e;
    }
    f->fim = e;
    f->tamanho = f->tamanho + 1;
}

int size(FILA * f) {
    return f->tamanho;
}

int head(FILA * f) {
    return f->cabeca->valor;
}

int empty(FILA * f) {
    return f->tamanho == 0;
}

int dequeue(FILA * f) {
    ELEMENTO * e;
    int valor;
    if (!empty(f)) {
        e = f->cabeca;
        valor = e->valor;
        f->cabeca = e->proximo;
        if (empty(f)) {
            f->fim = NULL;
        }
        f->tamanho = f->tamanho - 1;
        free(e);
        return valor;
    } else {
        printf("Fila vazia\n");
        return '\0';
    }
}

FILA * criarNovaFila(FILA * f1, FILA * f2) {
    ELEMENTO * e1 = f1->cabeca;
    ELEMENTO * e2 = f2->cabeca;
    FILA * novaFila = iniciar();

    while (e1 != NULL && e2 != NULL) {
        if (e1->valor < e2->valor) {
            enqueue(novaFila, e1->valor);
            e1 = e1->proximo;
        } else {
            enqueue(novaFila, e2->valor);
            e2 = e2->proximo;
        }
    }

    while (e1 != NULL) {
        enqueue(novaFila, e1->valor);
        e1 = e1->proximo;
    }

    while (e2 != NULL) {
        enqueue(novaFila, e2->valor);
        e2 = e2->proximo;
    }

    return novaFila;
}

int main() {
    FILA * f1 = iniciar();
    FILA * f2 = iniciar();

    enqueue(f1, 2);
    enqueue(f1, 10);
    enqueue(f1, 15);
    enqueue(f1, 25);

    enqueue(f2, 3);
    enqueue(f2, 5);
    enqueue(f2, 9);
    enqueue(f2, 15);
    
    FILA * novaFila = criarNovaFila(f1, f2);
    ELEMENTO * e = novaFila->cabeca;
    while (e != NULL) {
        printf("%d ", e->valor);
        e = e->proximo;
    }
    
}