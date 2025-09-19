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
        free(e); // libera espaço ocupado pelo antigo topo da pilha, faz o oposto do malloc()
        e = NULL;
        return c;
    } else{
        printf("Pilha vazia\n");
        return "\n";
    }
}

#define I 10

int main(){
    // Inicializa a pilha
    Pilha *p = iniciar();
    char palavraOuFrase[I];

    printf("Digite algo:\n");
    fgets(palavraOuFrase, I, stdin);

    int tam = strlen(palavraOuFrase);
    if (palavraOuFrase[tam - 1] == '\n') {
        palavraOuFrase[tam - 1] = '\0';
        tam--;
    }

    char palindromo[I];
    for (int i = 0; i < tam; i++){
        push(p, palavraOuFrase[i]);
    }

    int i = 0;
    while (!empty(p)){
        char topo = pop(p);
        palindromo[i] = topo;
        i++;
    }
    palindromo[i] = '\0';  // adiciona o caractere nulo no final da string

    int comparacao = strcmp(palavraOuFrase, palindromo);
    if(comparacao == 0){
        printf("E um palindromo!\n");
    } else{
        printf("Nao e um palindromo!\n");
    }
    return 0;
}