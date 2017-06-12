/*
 ============================================================================
 Arquivo     : Lista Estática (.h)
 Autor       : Giordano Berwanger (Cryogenio)
 ============================================================================
 */

#define TAM_VETOR 1000000 ///TAMANHO DA LISTA
#define numBucket 100
typedef struct
{
    float *Dado[TAM_VETOR];
    int qtdElementos;
    int maxElementos;
}listaEstatica;

typedef struct {
    float topo;
    float balde[numBucket];
}bucket;

/// -------- FUNCOES LISTA --------
listaEstatica* CriaLista    ();
int            DestroiLista (listaEstatica *Li);
int            InsereFim    (listaEstatica *Li, float *Dado);
int            InsereInicio (listaEstatica *Li, float *Dado);
int            InserePos    (listaEstatica *Li, float *Dado, int Pos);
int            RemovePos    (listaEstatica *Li, int Pos);
float*         BuscaPos     (listaEstatica *Li, int Pos);
int            Altera       (listaEstatica *Li, int Pos, float *novoDado);
void           ExibeLista   (listaEstatica *Li);
float          BuscaDado    (listaEstatica *Li, float *Dado);
void           Popula       (listaEstatica *Li);
float          MaxMin1      (listaEstatica *Li);
void           MaxMin2      (listaEstatica *Li, float max, float min);
void           MaxMin3      (listaEstatica *Li, float max, float min);
int            OurRandomi   (int num);

/// -------- ALGORITMOS DE ORDENACAO --------
void           bubbleSort      (listaEstatica *Li);
void           insertionSort   (listaEstatica *Li);
void           selectionSort   (listaEstatica *Li);
void           shellSort       (listaEstatica *Li);
void           Swap            (listaEstatica *Li, int esq, int dir);
void           quickSort       (listaEstatica *Li, int inicio, int fim);
void           heapSort        (listaEstatica *Li);
void           countingSort    (listaEstatica *Li);
void           mergeSort       (listaEstatica *Li, int p, int r);
void           countingSort    (listaEstatica *Li);
void           radixSort       (listaEstatica *Li);
void           bubble          (float v[], int tam);
void           bucketSort1     (listaEstatica *Li);
void           bucketSort2     (listaEstatica *Li);

