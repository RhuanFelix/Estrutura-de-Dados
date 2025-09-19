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
        return "\0";
    }
}

int main(void){
    Pilha *p = iniciar();
    char expressao[100];
    printf("Digite uma expressao: ");
    scanf("%s", &expressao);
    int tam = strlen(expressao);
    for(int i = 0; i < tam; i++){
        if(strcmp(expressao, " ") == 0){
            break;
        } else{
            if(expressao[i] == '{'){
                push(p, '}');
            }
            if(expressao[i] == '['){
                push(p, ']');
            }
            if(expressao[i] == '('){
                push(p, ')');
            }
        }
    }

    if(empty(p) && strcmp(expressao, " ") == 0){
        printf("Nao tem nenhuma expressao!\n");
    } else if(empty(p)){
        printf("Voce nao adicionou chaves, colchetes ou parenteses na expressao, mas ela esta balanceada!\n");
    }
    else{
        for(int i = 0; i < tam; i++){
            if(strcmp(expressao, " ") == 0){
                break;
            } else{
                if((expressao[i] == '}' && '}' == p->topo->valor) || (expressao[i] == ']' && ']' == p->topo->valor) || (expressao[i] == ')' && ')' == p->topo->valor)){
                    pop(p);
                }
            }
        }
        if(!empty(p)){
            printf("A expressao nao esta balanceada!\n");
        } else if(empty(p) && strcmp(expressao, " ") != 0){
            printf("A expressao esta balanceada!\n");
        }        
    }

    return 0;
}