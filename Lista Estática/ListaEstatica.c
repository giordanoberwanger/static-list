#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "ListaEstatica.h"

listaEstatica* CriaLista()
{

    listaEstatica* Li = (listaEstatica*) malloc (sizeof(listaEstatica));

    if( !Li )
        return NULL;

    Li->maxElementos = TAM_VETOR;
    Li->qtdElementos = 0;

    return Li;
}

int DestroiLista (listaEstatica *Li)
{

    if( !Li )
        return 0;

    free(Li);

    return 1;
}

int InsereFim (listaEstatica *Li, float *Dado)
{

    if( !Li )
        return -1;

    if( Li->qtdElementos == Li->maxElementos )
        return 0;

    Li->Dado[Li->qtdElementos] = Dado;
    Li->qtdElementos++;

    return 1;
}

int InsereInicio (listaEstatica *Li, float *Dado)
{

    int i;

    if( Li->qtdElementos == Li->maxElementos )
        return 0;

    for (i = Li->qtdElementos; i >= 0; i--)
        Li->Dado[i+1] = Li->Dado[i];

    Li->Dado[0] = Dado;
    Li->qtdElementos++;

    return 1;
}

int InserePos (listaEstatica *Li, float *Dado, int Pos)
{

    int i;

    if( !Li )
        return -1;

    if( Pos > Li->maxElementos || Pos < 0 )
        return -2;

    if( Li->qtdElementos >= Li->maxElementos )
        return 0;

    for (i = Li->qtdElementos; i >= Pos; i--)
        Li->Dado[i+1] = Li->Dado[i];

    Li->Dado[Pos] = Dado;
    Li->qtdElementos++;

    return 1;
}

int RemovePos (listaEstatica *Li, int Pos)
{

    int i;
    for (i = Li->qtdElementos; i > Pos; i--)
        Li->Dado[i+1] = Li->Dado[i];

    Li->qtdElementos--;
    return 1;
}

int Altera (listaEstatica *Li, int Pos, float *novoDado)
{
    Li->Dado[Pos] = novoDado;
    return 1;
}

float* BuscaPos (listaEstatica *Li, int Pos)
{
    return Li->Dado[Pos];
}

float BuscaDado (listaEstatica *Li, float *Dado)
{
    int i;
    for(i = 0; i<Li->qtdElementos; i++)
    {
        if(*Li->Dado[i] == *Dado)
            return *Li->Dado[i];
    }
    return 0;
}

void ExibeLista (listaEstatica *Li)
{
    int i,cont=0;
    for(i = 0; i < Li->qtdElementos; i++)
    {
        printf("%.1f -> ", *Li->Dado[i]);
        cont++;
        if(cont == 15)
        {
            cont =0;
            printf("\n");
        }
    }
    printf("NULL\n");
}

/// --------------------- LISTA EXERCÍCIO PESQUISA E CLASSIFICAÇÃO --------------------------------//

float MaxMin1 (listaEstatica *Li)
{
    // clock_t start = clock();
    //Sleep(1);
    int i;
    float max, min;
    min = *Li->Dado[0];
    max = *Li->Dado[0];

    for(i=0; i<Li->qtdElementos; i++)
    {
        if(*Li->Dado[i] > max) max = *Li->Dado[i];
        if(*Li->Dado[i] < min) min = *Li->Dado[i];
    }

    //clock_t stop = clock();
    // printf("%2.10lf\n", ((stop-start)*1000.0)/CLOCKS_PER_SEC);
    //printf("MAIOR = %f\nMENOR = %f\n", max, min);
    return max;
}

void MaxMin2 (listaEstatica *Li, float max, float min)
{
    clock_t start = clock();
    Sleep(1);
    int i;
    min = *Li->Dado[0];
    max = *Li->Dado[0];

    for(i=0; i<Li->qtdElementos; i++)
    {
        if(*Li->Dado[i] > max) max = *Li->Dado[i];
        else if(*Li->Dado[i] < min) min = *Li->Dado[i];
    }
    clock_t stop = clock();
    printf("%2.10lf\n", ((stop-start)*1000.0)/CLOCKS_PER_SEC);
    printf("MAIOR = %f\nMENOR = %f\n", max, min);
}

void MaxMin3 (listaEstatica *Li, float max, float min)
{
    clock_t start = clock();
    Sleep(1);
    int i, fim;
    if( (TAM_VETOR %2) > 0)
    {
        Li->Dado[TAM_VETOR] = Li->Dado[TAM_VETOR-1];
        fim = TAM_VETOR;
    }
    else fim = TAM_VETOR -1;

    if(*Li->Dado[0] > *Li->Dado[1])
    {
        max = *Li->Dado[0];
        min = *Li->Dado[1];
    }
    else
    {
        max = *Li->Dado[1];
        min = *Li->Dado[0];
    }

    for(i=3; i<=fim; i+=2)
    {
        if(*Li->Dado[i-1] > *Li->Dado[i])
        {
            if(*Li->Dado[i-1] > max) max = *Li->Dado[i-1];
            if(*Li->Dado[i] < min) min = *Li->Dado[i];
        }
        else
        {
            if(*Li->Dado[i-1] < min) min = *Li->Dado[i-1];
            if(*Li->Dado[i] > max) max = *Li->Dado[i];
        }
    }
    clock_t stop = clock();
    printf("%2.10lf\n", ((stop-start)*1000.0)/CLOCKS_PER_SEC);
    printf("MAIOR = %.1f\nMENOR = %.1f\n", max, min);
}

int OurRandom (int num)
{
    char *res = (char*) malloc (32 * sizeof(char));
    unsigned int i, num2 = num;
    int result = 0;
    int exp = 31;

    for(i=0; i<32; i++)
    {
        res[i] = rand() % 2;
    }

    for(i=0; i<32; i++)
        result += res[i] * pow(2, exp--);

    result %= num2;
    return result;
}

void Popula (listaEstatica *Li)
{
    float *dado;
    int i;
    for(i=0; i<Li->maxElementos; i++)
    {
        dado = (float*) malloc(sizeof(float));
        *dado = (float) OurRandom(TAM_VETOR);

        InsereFim(Li, dado);
    }
}


/// --------------------- ALGORITMOS DE ORDENAÇÃO - PESQUISA E CLASSIFICAÇÃO --------------------------------//
/// .BUBBLESORT - .INSERTIONSORT - .SELECTIONSORT - .SHELLSORT - .MERGESORT
/// .QUICKSORT  - .HEAPSORT    - .COUNTINGSORT  - .RADIXSORT - .BUCKETSORT

void bubbleSort (listaEstatica *Li) ///CERTO
{
    int i,j;
    float *aux;

    for(i=Li->qtdElementos-1; i>0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(*Li->Dado[j] > *Li->Dado[j+1])
            {
                aux = Li->Dado[j];
                Li->Dado[j] = Li->Dado[j+1];
                Li->Dado[j+1] = aux;
            }
        }
    }
}

void insertionSort (listaEstatica *Li) ///CERTO
{
    int i,j;
    float *aux;

    for (i=0; i<Li->qtdElementos; i++)
    {
        aux = Li->Dado[i];
        j = i-1;
        while(j>=0 && (*aux < *Li->Dado[j]))
        {
            Li->Dado[j+1] = Li->Dado[j];
            j--;
        }
        Li->Dado[j+1] = aux;
    }
}

void selectionSort (listaEstatica *Li) ///CERTO
{
    int i,j, min;
    float *aux;

    for(i=0; i<Li->qtdElementos-1; i++)
    {
        min = i;
        for(j=i+1; j<Li->qtdElementos; j++)
        {
            if(*Li->Dado[j] < *Li->Dado[min])
                min = j;
        }
        aux = Li->Dado[i];
        Li->Dado[i] = Li->Dado[min];
        Li->Dado[min] = aux;
    }
}

void shellSort (listaEstatica *Li) ///CERTO
{
    int i, j, h=1;
    float *aux;

    do
    {
        h = 3*h +1;
    }
    while(h < Li->qtdElementos);
    do
    {
        h/=3;
        for(i=h; i<Li->qtdElementos; i++)
        {
            aux = Li->Dado[i];
            j = i-h;

            while(j>=0 && *aux < *Li->Dado[j])
            {
                Li->Dado[j+h] = Li->Dado[j];
                j-=h;
            }
            Li->Dado[j+h] = aux;
        }
    }
    while(h>1);
}

void Swap(listaEstatica *Li, int esq, int dir) ///CERTO
{
    float *aux;
    aux = Li->Dado[esq];
    Li->Dado[esq] = Li->Dado[dir];
    Li->Dado[dir] = aux;
}

void quickSort (listaEstatica *Li, int inicio, int fim) ///CERTO
{
    int esq, dir;
    float *pivot;

    if(inicio >= fim)
        return;

    esq = inicio;
    dir = fim;

    pivot = Li->Dado[(inicio+fim)/2];

    while( esq <= dir )
    {
        while( *Li->Dado[esq] < *pivot )
            esq++;
        while( *Li->Dado[dir] > *pivot )
            dir--;

        if(esq <= dir)
        {
            Swap(Li, esq, dir);
            esq++;
            dir--;
        }
    }
    quickSort(Li, inicio, dir);
    quickSort(Li, esq, fim);
}

void rebuild_up_Down (listaEstatica *Li, int k, int n)
{
    int j;
    while(2*k <= n)
    {
        j = 2*k;
        if(j < n && *Li->Dado[j] < *Li->Dado[j+1])
            j++;
        if(*Li->Dado[k] >= *Li->Dado[j])
            break;

        Swap(Li,k,j);
        k=j;
    }
}

void buildHeap(listaEstatica *Li)
{
    int k = Li->qtdElementos-1/2;
    while(k >= 1)
    {
        rebuild_up_Down(Li,k,Li->qtdElementos-1);
        k--;
    }
}

void heapSort(listaEstatica *Li) ///FUNCIONA PARA TODOS MENOS PARA O PRIMEIRO ELEMENTO
{
    buildHeap(Li);
    int k = Li->qtdElementos-1;
    while(k >= 1)
    {
        Swap(Li,k,1);
        k--;
        rebuild_up_Down(Li,1,k);
    }
}

void intercala (listaEstatica *Li, int l, int m, int r) ///NAO FUNCIONA
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    float L[n1], R[n2];

    for(i=0; i<n1; i++)
        L[i] = *Li->Dado[l+i];

    for(j=0; j<n2; j++)
        R[j] = *Li->Dado[m + 1 + j];

    i=0; j=0; k=l;
    while(i < n1 && j <n2){
        if(L[i] <= R[j]){
            *Li->Dado[k] = L[i];
            i++;
        }
        else{
            *Li->Dado[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        *Li->Dado[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        *Li->Dado[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort (listaEstatica *Li, int l, int r) ///NAO FUNCIONA
{
    if( l < r )
    {
        int m = l+(r-1)/2;
        mergeSort(Li, l, m);
        mergeSort(Li, m+1, r);
        intercala(Li, l, m, r);
    }
}

void countingSort (listaEstatica *Li) ///CERTO
{
    int tam = Li->qtdElementos-1, i, j;
    float auxVecB[tam], max = MaxMin1(Li);
    float auxVecX[(int)max + 1];

    for(i=0; i<max+1; i++)
        auxVecX[i] = 0;

    for(i=0; i<tam+1; i++)
        auxVecX[(int)*Li->Dado[i]]++;

    j=0;
    for(i=0; i<max+1; i++)
        while( auxVecX[i] != 0)
        {
            auxVecB[j] = i;
            j++;
            auxVecX[i]--;
        }

    for(i=0; i<tam+1; i++)
        *Li->Dado[i] = auxVecB[i];
}

void radixSort (listaEstatica *Li) ///CERTO
{
    int i, max = MaxMin1(Li), exp = 1;
    float *b = (float*) malloc (Li->qtdElementos-1 * sizeof(float));

    while((max/exp)>0)
    {
        float bucket[10] = {0};

        for(i=0; i<Li->qtdElementos; i++)
            bucket[(int)(*Li->Dado[i]/exp)%10]++;
        for(i=0; i<10; i++)
            bucket[i] += bucket[i-1];
        for(i=Li->qtdElementos-1; i>=0; i--)
            b[(int)--bucket[((int)*Li->Dado[i]/exp)%10]] = *Li->Dado[i];
        for(i=0; i<Li->qtdElementos; i++)
            *Li->Dado[i] = b[i];
        exp *= 10;
    }

    free(b);
}

void bubble (float v[], int tam)
{
    int i,j,temp,flag;
    if(tam)
        for(j=0; j<tam-1; j++)
        {
            flag=0;
            for(i=0; i<tam-1; i++)
            {
                if(v[i+1]<v[i])
                {
                    temp=v[i];
                    v[i]=v[i+1];
                    v[i+1]=temp;
                    flag=1;
                }
            }
            if(!flag)
                break;
        }
}

void bucketSort1 (listaEstatica *Li)
{
    bucket b[numBucket];
    int i, j, k;

    for(i=0; i<numBucket; i++)
        b[i].topo = 0;

    for(i=0; i<Li->qtdElementos; i++)
    {
        j = numBucket-1;

        while(1)
        {
            if(j<0)
                break;
            if(*Li->Dado[i] >= j*10)
            {
                b[j].balde[(int)b[j].topo] = *Li->Dado[i];
                (b[j].topo)++;
                break;
            }
            j--;
        }
    }

    for(i=0; i<numBucket; i++)
        if(b[i].topo)
            bubble(b[i].balde, b[i].topo);

    i=0;
    for(j=0; j<numBucket; j++)
    {
        for(k=0; k<b[j].topo; k++)
        {
            *Li->Dado[i] = b[j].balde[k];
            i++;
        }
    }
}

void bucketSort2(listaEstatica *Li)
{
    int i,j;
    float cont[Li->qtdElementos-1];

    for(i=0; i<Li->qtdElementos; i++)
        cont[i] = 0;

    for(i=0; i<Li->qtdElementos-1; i++)
        (cont[(int)*Li->Dado[i]])++;

    for(i=0, j=0; i<Li->qtdElementos; i++)
        for(; cont[i]>0; (cont[i])--)
            *Li->Dado[j++] = i;
}













































