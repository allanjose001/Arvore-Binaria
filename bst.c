#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void preOrder(Folha *raiz) {
    if (raiz) {
        printf("%d ", raiz->valor);
        preOrder(raiz->esquerda);
        preOrder(raiz->direita);
    }
}

void inOrder(Folha *raiz) {
    if (raiz) {
        inOrder(raiz->esquerda);
        printf("%d ", raiz->valor);
        inOrder(raiz->direita);
    }
}

int altura(Folha *raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if (esq > dir) {
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}

//inserção recursiva com retorno
Folha* inserir(Folha *raiz, int num) {
    if (raiz == NULL) {
        Folha *novo = malloc(sizeof(Folha));
        novo->valor = num;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if (num < raiz->valor) {
            raiz->esquerda = inserir(raiz->esquerda, num);
        } else {
            raiz->direita = inserir(raiz->direita, num);
        }
        return raiz;
    }
}

//inserção recursiva sem utilizar retorno
void inserir2(Folha **raiz, int num) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(Folha));
        (*raiz)->valor = num;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;

    } else {
        if (num < (*raiz)->valor){
            inserir2(&((*raiz)->esquerda), num);
        } else {
            inserir2(&((*raiz)->direita), num);
        }
    }
}

//inserção iterativa sem retorno
void inserir3(Folha **raiz, int num) {
    Folha *novo = *raiz;

    while(novo) {
        if (num < novo->valor) {
            raiz = &novo->esquerda;
        } else {
            raiz = &novo->direita;
        }
        novo = *raiz;

    }
    novo = malloc(sizeof(Folha));
    novo->valor = num;
    novo->esquerda = NULL;
    novo->direita = NULL;
    *raiz = novo;
}

//busca recursiva
Folha* busca1(Folha *raiz, int num) {
    if (raiz) {
        if (num == raiz->valor) {
            return raiz;
        } else if (num < raiz->valor) {
            return busca1(raiz->esquerda, num);
        } else {
            return busca1(raiz->direita, num);
        }
    }
    return NULL;
}

//busca iterativa
Folha* busca2(Folha *raiz, int num) {
    while (raiz) {
        if (num < raiz->valor) {
            raiz = raiz->esquerda;
        } else if (num > raiz->valor) {
            raiz = raiz->direita;
        } else {
            return raiz;
        }
    }
    return NULL;
}

Folha* remover(Folha *raiz, int num) {
    //função muito complexa, ver video 274 - 276 da playlist de programação em C

    //se raiz estiver vazia encerra. Se não percorre a Arvore
    if (raiz == NULL) {
        printf("\nvalor nao encontrado\n");
        return NULL;
    } else {
        //se o numero que está sendo procurado estiver na raiz/folha atual, remove ela,
        //se não, faz chamada recursiva para percorrer a arvore
        if (raiz->valor == num) {
            //essa remoção só é utilizada quando o item atual está na "ponta" da arvore,
            //por que a sua esquerda e direita estão NULLs, logo não tem nada com o que se preocupar ao remove-lo
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("\n\tFolha removida\n\t");
                return NULL;
            } else {
                //se ambos os lados da folha atual não são NULLs, então cria uma variavel auxiliar.
                //por escolha propia, eu decido que vou armazenar o galho esquerdo do item atual
                //e então percorro a direita deste galho até que o ponteiro "direita" seja NULL,
                //não coincidentemente, o valor encontrado é numero antecessor ao atual.
                if (raiz->esquerda != NULL && raiz->direita != NULL) {
                    Folha *aux = raiz->esquerda;
                    while (aux->direita != NULL) {
                        aux = aux->direita;
                    }

                    //e então eu troco o NUMERO da folha original com o da folha que está no fim do galho
                    raiz->valor = aux->valor;
                    aux->valor = num;
                    //desta forma, o valor que eu quero remover agora está na ponta da arvore.
                    //por fim, basta fazer chamada recursiva para que ele seja removido
                    //afinal, agora que o valor está em uma folha que está na ponta da arvore,
                    //sabe-se que não há mais problemas em remove-lo
                    raiz->esquerda = remover(raiz->esquerda, num);
                    return raiz;
                } else {
                    //se a folha possui 1 galho, retorna o galho e remove a folha desejada
                    Folha *aux;
                    if (raiz->esquerda != NULL) {
                        aux = raiz->esquerda;
                    } else {
                        aux = raiz->direita;
                    }
                    free(raiz);
                    return aux;
                }
            }
        } else {
            //percorre a Folha até achar o valor desejado
            if (num < raiz->valor) {
                raiz->esquerda = remover(raiz->esquerda, num);
            } else {
                raiz->direita = remover(raiz->direita, num);
            }
            return raiz;
        }
    }
}