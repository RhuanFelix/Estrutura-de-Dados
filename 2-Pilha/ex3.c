/* Crie um programa em C que elimine o maior e o menor número, dado a seguinte sequência de push em uma pilha:
    push(p, 30);
    push(p, 10);
    push(p, 20);
    push(p, 50);
    push(p, 40);*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    int valor;
    struct elemento * proximo;
} ELEMENTO;

typedef struct pilha{
    ELEMENTO * topo;
    int tamanho;
} PILHA;

PILHA * iniciar(){
    PILHA * p = (PILHA *)malloc(sizeof(PILHA));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void push(PILHA * p, int valor){
    ELEMENTO * e = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    e->valor = valor;
    e->proximo = p->topo;
    p->topo = e;
    p->tamanho = p->tamanho + 1;
}

int empty(PILHA * p){
    return p->tamanho == 0;
}

int pop(PILHA * p){
    ELEMENTO * e;
    int v;
    if(!empty(p)){
        e = p->topo;
        v = e->valor;
        p->topo = p->topo->proximo;
        p->tamanho = p->tamanho - 1;
        free(e);
        e = NULL;
        return v;
    } else{
        printf("Pilha vazia\n");
        return -1;
    }
}

void removerElemento(PILHA *p, int valor) {
    ELEMENTO *atual = p->topo;
    ELEMENTO *anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                p->topo = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            p->tamanho--;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void excluirMaiorMenor(PILHA * p){
    if (empty(p)) return;
    ELEMENTO * e = p->topo;
    int maior = e->valor;
    int menor = e->valor;
    while(e != NULL){
        if(e->valor > maior) maior = e->valor;
        if(e->valor < menor) menor = e->valor;
        e = e->proximo;
    }
    removerElemento(p, maior);
    removerElemento(p, menor);
}

int main(){
    PILHA * p = iniciar();
    push(p, 30);
    push(p, 10);
    push(p, 20);
    push(p, 50);
    push(p, 40);
    excluirMaiorMenor(p);

    ELEMENTO * e = p->topo;
    while (e != NULL) {
        printf("%d ", e->valor);
        e = e->proximo;
    }

    return 0;
}