#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char *argv[]) {
    Folha *busca, *raiz = NULL;
    int opcao, valor;

    do {
        printf("\n\t0 - sair\n\t1 - inserir\n\t2 - imprimir\n\t3 - buscar\n\t4 - altura\n\t5 - remover\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n\tdigite um valor: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                //inserir2(&raiz, valor);
                //inserir3(&raiz, valor);   

                break;
            case 2:
                printf("\n\timpressao pre-order: \n\t");
                preOrder(raiz);
                printf("\n\timpressao in-oder: \n\t");
                inOrder(raiz);
                printf("\n");
                break;
            case 3:
                printf("\n\tDigite o valor a ser buscado: \n\t");
                scanf("%d", &valor);
                busca = busca1(raiz, valor);
                //busca = busca2(raiz, valor);
                if (busca) {
                    printf("\n\tvalor encontrado: %d\n\t", busca->valor);
                } else {
                    printf("\n\tvalor não encontrado\n\t");
                }
                break;
            case 4:
                printf("\n\tAltura da Folha: %d", altura(raiz));
                break;

            case 5:
                printf("\n\tdigite o valor a ser removido\n\t");
                scanf("%d", &valor);
                raiz = remover(raiz,valor);
                break;
                
            default:
                if (opcao != 0) {
                    printf("\n\topcao invalida");
                }
        }


    } while(opcao != 0);

    return 0;
}