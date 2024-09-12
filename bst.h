#include <stdio.h>
#include <stdlib.h>

typedef struct folha {
    int valor;
    struct folha *direita, *esquerda;
} Folha;

int altura(Folha *raiz);
void preOrder(Folha *raiz);
void inOrder(Folha *raiz);
Folha* busca1(Folha *raiz, int num);
Folha* inserir(Folha *raiz, int num);
Folha* remover(Folha *raiz, int chave);
