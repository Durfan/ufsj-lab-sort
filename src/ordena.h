#define MAX_TAM 50

typedef int ChaveTipo;
typedef int Indice;

typedef struct Item {
    ChaveTipo chave;
    /* outros componentes */
} Item;

typedef Item Vetor[MAX_TAM + 1];

void selecao(Vetor a, Indice *n);
void insercao(Vetor a, Indice *n);
void shellsort(Vetor a, Indice *n);

void particionar(Indice esq, Indice dir, Indice *i, Indice *j, Vetor a);
void ordenar(Indice esq, Indice dir, Vetor a);
void quicksort(Vetor a, Indice *n);

void refazer(Indice esq, Indice dir, Vetor a);
void construir(Vetor a, Indice *n);