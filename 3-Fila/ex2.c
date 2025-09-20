/*
Implemente um programa em C que manipule 2 filas de char. A primeira, chamada de "f1",
deve conter os caracteres A, C, E, G, I, K, M, O, Q, S, U, W e Y. A segunda, chamada
de "f2", deve conter os caracteres B, D, F, H, J, L, N, P, R, T, V e Z. O programa
deve exibir o alfabeto na ordem de A até Z.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    char valor;
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

void enqueue(FILA * f, char valor) {
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

char head(FILA * f) {
    return f->cabeca->valor;
}

int empty(FILA * f) {
    return f->tamanho == 0;
}

char dequeue(FILA * f) {
    ELEMENTO * e;
    char valor;
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

void listarEmOrdemAlfabetica(FILA * f1, FILA * f2) {
    while (!empty(f1) && !empty(f2)) {
        printf("%c\n", dequeue(f1));
        printf("%c\n", dequeue(f2));
    }
    
}

int main() {
    FILA * f1 = iniciar();
    FILA * f2 = iniciar();

    enqueue(f1, 'A');
    enqueue(f1, 'C');
    enqueue(f1, 'E');
    enqueue(f1, 'G');
    enqueue(f1, 'I');
    enqueue(f1, 'K');
    enqueue(f1, 'M');
    enqueue(f1, 'O');
    enqueue(f1, 'Q');
    enqueue(f1, 'S');
    enqueue(f1, 'U');
    enqueue(f1, 'W');
    enqueue(f1, 'Y');

    enqueue(f2, 'B');
    enqueue(f2, 'D');
    enqueue(f2, 'F');
    enqueue(f2, 'H');
    enqueue(f2, 'J');
    enqueue(f2, 'L');
    enqueue(f2, 'N');
    enqueue(f2, 'P');
    enqueue(f2, 'R');
    enqueue(f2, 'T');
    enqueue(f2, 'V');
    enqueue(f2, 'X');
    enqueue(f2, 'Z');

    listarEmOrdemAlfabetica(f1, f2);
    return 0;
}