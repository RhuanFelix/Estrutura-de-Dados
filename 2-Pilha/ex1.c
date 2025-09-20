/*
Um palíndromo é uma palavra, frase ou número pode ser lido de forma igual em ambos os sentidos:
da direita para a esquerda e da esquerda para a direita. Ex.: arara, 202, "anotaram a data da maratona".
Crie um programa em C que verifica se uma palavra, frase ou número é um palíndromo. Dicas: use uma pilha e faça
o empilhamento e a verificação a cada desempilhamento com a palavra, frase ou número. Escolha entre palavra, frase
ou número, pois as diferenças entre estes pode dificultar na resolução. Se quiser, faça um programa para cada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    char valor;
    struct elemento *proximo;
} Elemento;

typedef struct pilha{
    Elemento *topo;
    int tamanho;
} Pilha;

Pilha* iniciar(){
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void push(Pilha *p, char caractere){
    Elemento *e = (Elemento *) malloc(sizeof(Elemento));
    e->valor = caractere;
    e->proximo = p->topo;
    p->topo = e;
    p->tamanho = p->tamanho + 1;
}

int empty(Pilha *p){
    return p->tamanho == 0;
}

char pop(Pilha *p){
    Elemento *e;
    char c;
    if(!empty(p)){
        e = p->topo;
        c = e->valor;
        p->topo = p->topo->proximo;
        p->tamanho = p->tamanho - 1;
        free(e);
        e = NULL;
        return c;
    } else{
        printf("Pilha vazia\n");
        return '\0';
    }
}

#define MAX 100

int verificarPalindromo(Pilha * p) {
    int tamanho = p->tamanho;
    char nome[MAX];
    Elemento * e = p->topo;
    int i = 0;
    while (e != NULL) {
        nome[i++] = e->valor;
        e = e->proximo;
    }
    nome[tamanho] = '\0';

    int ePalindromo = 1;
    for (int j = tamanho - 1; j >= 0; j--) {
        if (nome[j] != pop(p)) {
            ePalindromo = 0;
            break;
        }
    }
    return ePalindromo;
}

int main(){
    Pilha * p = iniciar();

    push(p, 'a');
    push(p, 'n');
    push(p, 'a');

    int resultado = verificarPalindromo(p);

    if (resultado == 1) {
        printf("E palindromo!\n");
    } else {
        printf("Nao e palindromo!\n");
    }
    
    return 0;
}