#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "ListaEstatica.h"

enum Opcoes
{
    EXIBIR=1,
    INSERIR,
    EXCLUIR,
    ALTERAR,
    BUSCAPOS,
    BUSCADADO,
    POPULA,
    PESQUISA,
    SAIR
};

int main()
{
    float *valor, max=0, min=0;
    int Busca, op = 0, op2, op3;
    srand( (unsigned)time(NULL) );
    listaEstatica *ptrLista = CriaLista();

    while(op != SAIR)
    {
        printf("------MENU------\n[1] Exibir Lista\n[2] Inserir Elemento\n[3] Excluir Elemento\n[4] Alterar Elemento\n[5] Busca Por Posicao\n[6] Busca Por Dado\n[7] Popula Lista\n[8] Funcoes Pesuisa e Classificacao\n[9] Sair\nOpcao: ");
        scanf("%d",&op);
        switch(op)
        {

        case EXIBIR:
        {
            system("cls");
            ExibeLista(ptrLista);
            break;
        }

        case INSERIR:
        {
            system("cls");
            printf("[1] Inserir no Inicio\n[2] Inserir no Meio\n[3] Inserir no Final\n[4] Retornar ao Menu\nOpcao: ");
            scanf("%d",&op2);
            if(op2 == 1)
            {
                printf("Digite o valor a ser inserido: ");
                valor = (float*) malloc(sizeof(float));
                scanf("%f", valor);
                InsereInicio(ptrLista, valor);
            }

            if(op2 == 2)
            {
                printf("Digite o valor a ser inserido: ");
                valor = (float*) malloc(sizeof(float));
                scanf("%f", valor);
                printf("Digite a posicao que sera inserida: ");
                scanf("%d",&Busca);
                InserePos(ptrLista, valor, Busca);
            }

            if(op2 == 3)
            {
                printf("Digite o valor a ser inserido: ");
                valor = (float*) malloc(sizeof(float));
                scanf("%f", valor);
                InsereFim(ptrLista, valor);
            }

            if(op2 == 4)
            {
                system("cls");
                break;
            }

            break;
        }

        case EXCLUIR:
        {
            system("cls");
            printf("Digite o indice do elemento a ser excluido: ");
            scanf("%d",&Busca);
            RemovePos(ptrLista,Busca);
            break;
        }

        case ALTERAR:
        {
            system("cls");
            printf("Digite o Indice do Elemento que deseja alterar: ");
            scanf("%d",&Busca);
            printf("Digite o novo valor do dado:");
            valor = (float*) malloc(sizeof(float));
            scanf("%f",valor);
            Altera(ptrLista, Busca, valor);
            break;
        }

        case BUSCAPOS:
        {
            system("cls");
            printf("Digite a posicao que deseja buscar:");
            scanf("%d",&Busca);
            printf("Resultados encontrados: %.1f\n",*BuscaPos(ptrLista, Busca));
            break;
        }

        case BUSCADADO:
        {
            system("cls");
            printf("Digite o dado que deseja buscar:");
            valor = (float*) malloc(sizeof(float));
            scanf("%f",valor);
            printf("Resultados encontrados: %.1f\n", BuscaDado(ptrLista, valor));
            break;
        }
        case POPULA:
        {
            Popula(ptrLista);
            break;
        }

        case PESQUISA:
        {
            system("cls");
            printf("[1] Algoritmos de Ordenacao\n[2] Algoritmos MaxMin\nOpcao: ");
            scanf("%d",&op2);

            if(op2 == 2)
            {
                printf("[1] MaxMin1\n[2] MaxMin2\n[3] MaxMin3\n[4] Retornar ao Menu\nOpcao: ");
                scanf("%d",&op3);
                if(op3 == 1)
                    MaxMin1(ptrLista);

                if(op3 == 2)
                    MaxMin2(ptrLista, max, min);

                if(op3 == 3)
                    MaxMin3(ptrLista, max, min);

                if(op3 == 4)
                {
                    system("cls");
                    break;
                }
            }

            if(op2 == 1)
            {
                printf("[1] BubbleSort\n[2] InsertionSort\n[3] SelectionSort\n[4] ShellSort\n[5] QuickSort\n[6] HeapSort\n[7] MergeSort\n[8] CountingSort\n[9] RadixSort\n[10] BucketSort\n[11] Retornar ao Menu\nOpcao: ");
                scanf("%d",&op3);

                if(op3 == 1)
                    bubbleSort(ptrLista);

                if(op3 == 2)
                    insertionSort(ptrLista);

                if(op3 == 3)
                    selectionSort(ptrLista);

                if(op3 == 4)
                    shellSort(ptrLista);

                if(op3 == 5)
                    quickSort(ptrLista, 0, ptrLista->qtdElementos-1);

                if(op3 == 6)
                    heapSort(ptrLista);

                if(op3 == 7)
                    mergeSort(ptrLista, 0, ptrLista->qtdElementos-1);

                if(op == 8)
                    countingSort(ptrLista);

                if(op == 9)
                    radixSort(ptrLista);

                if(op == 10)
                    bucketSort1(ptrLista);

                if( (op3 >= 10) || (op3 < 1) )
                {
                    system("cls");
                    break;
                }
            }
            break;
        }

        case SAIR:
        {
            exit(1);
        }
        default:
        {
            printf("Valor Invalido\n");
            break;
        }
        }
    }

    DestroiLista(ptrLista);
    return 0;
}
