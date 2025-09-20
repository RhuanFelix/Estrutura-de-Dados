/*
Implemente um programa em C que manipule 3 filas de números inteiros. A primeira,
chamada de "f", deve conter os números de 1 até 15. A segunda, chamada de "f_par",
está inicialmente vazia, assim como a terceira, chamada de "f_impar". O programa
deve transferir os números pares de "f" para a fila "f_par" e os números ímpares
de "f" para a fila "f_impar"
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

void transferirNumeros(FILA * f_origem, FILA * f_destino_par, FILA * f_destino_impar) {
    while (!empty(f_origem)) {
        int valor = head(f_origem);
        if (valor % 2 == 0) {
            enqueue(f_destino_par, valor);
        } else {
            enqueue(f_destino_impar, valor);
        }
        dequeue(f_origem);
    }
}

void listar(FILA * f) {
    if (!empty(f)) {
        ELEMENTO * e = f->cabeca;
        while (e != NULL) {
            printf("%d\n", e->valor);
            e = e->proximo;
        }
    } else {
        printf("A fila está vazia\n");
    }
}

int main() {
    FILA * f = iniciar();
    FILA * f_par = iniciar();
    FILA * f_impar = iniciar();

    enqueue(f, 1);
    enqueue(f, 2);
    enqueue(f, 3);
    enqueue(f, 4);
    enqueue(f, 5);
    enqueue(f, 6);
    enqueue(f, 7);
    enqueue(f, 8);
    enqueue(f, 9);
    enqueue(f, 10);
    enqueue(f, 11);
    enqueue(f, 12);
    enqueue(f, 13);
    enqueue(f, 14);
    enqueue(f, 15);

    printf("Fila Principal:\n");
    listar(f);

    transferirNumeros(f, f_par, f_impar);

    printf("Fila de pares:\n");
    listar(f_par);

    printf("Fila de impares:\n");
    listar(f_impar);

    printf("\nFila Principal:\n");
    listar(f);
    return 0;
}