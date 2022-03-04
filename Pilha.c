#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define N 50

struct pilha{
    int n;
    int vet[N];
};

Pilha* pilha_cria(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; 
    return p;
}

void pilha_push(Pilha* p, int v){
    if(p->n == N){
        printf("Pilha cheia.\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

int pilha_pop(Pilha* p){
    int v;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    v = p->vet[p->n-1];
    p->n--;
    return v;
}

int pilha_vazia(Pilha* p){
    return (p->n == 0);
}

void pilha_libera(Pilha* p){
    free(p);
}

void pilha_imprime(Pilha* p){
    int i;
    for(i = p->n-1; i>=0; i--){
        printf("%i\n", p->vet[i]);
    }
}

int main(){
    Pilha* p = pilha_cria();
    pilha_push(p, 16);
    pilha_push(p, 59);
    pilha_push(p, 17);
    pilha_push(p, 5);
    pilha_push(p, 30);
    pilha_push(p, 94);

    printf("Primeiro elemento da pilha: %i\n", pilha_pop(p));
    printf("Segundo elemento da pilha: %i\n", pilha_pop(p));
    printf("Configuração da pilha: ");
    pilha_imprime(p);
    pilha_libera(p);

    return 1;
}