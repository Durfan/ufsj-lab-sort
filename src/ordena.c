#include "src/ordena.h"

// Ordenação por Seleção
void selecao(Vetor a, Indice *n) {
    Indice i, j, min;
    Item x;
    for (i = 1; i <= *n - 1; i++) {
        min = i;
        for (j = i + 1; j <= *n; j++) {
            if (a[j].chave < a[min].chave) {
                min = j;
            }
        }
        x = a[min];
        a[min] = a[i];
        a[i] = x;
    }
}

// Ordenação por Inserção
void insercao(Vetor a, Indice *n) {
    Indice i, j;
    Item x;
    for (i = 2; i <= *n; i++) {
        x = a[i];
        j = i - 1;
        a[0] = x; /* sentinela */
        while (x.chave < a[j].chave) {
            a[j+1] = a[j]; j--;
        }
        a[j+1] = x;
    }
}

// Shellsort
void shellsort(Vetor a, Indice *n) {
    int i, j;
    int h = 1;
    Item x;
    do h = h * 3 + 1; while (h < *n);
    do { h = (h-1)/3;
        for (i = h + 1; i <= *n; i++) {
            x = a[i];
            j = i;
            while (a[j - h].chave > x.chave) {
                a[j] = a[j - h];
                j -= h;
                if (j <= h) break;
            }
            a[j] = x;
        }
    } while (h != 1);
}

// Quicksort
void particionar(Indice esq, Indice dir, Indice *i, Indice *j, Vetor a) {
    Item x, w;
    *i = esq;
    *j = dir;
    x = a[(*i + *j) / 2]; /* obtem o pivo x */
    do {
        while (x.chave > a[*i].chave) (*i)++;
        while (x.chave < a[*j].chave) (*j)--;
        if (*i <= *j) {
            w = a[*i];
            a[*i] = a[*j];
            a[*j] = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void ordenar(Indice esq, Indice dir, Vetor a) {
    Indice i, j;
    particionar(esq, dir, &i, &j, a); 
    if (esq < j) ordenar(esq, j, a);
    if (i < dir) ordenar(i, dir, a);
}

void quicksort(Vetor a, Indice *n) {
    ordenar(1, *n, a);
}

// Heapsort
void refazer(Indice esq, Indice dir, Vetor a) {
    Indice i = esq;
    int j;
    Item x;
    j = i * 2;
    x = a[i];
    while (j <= dir) {
        if (j < dir) {
            if (a[j].chave < a[j+1].chave) j++;
        }
        if (x.chave >= a[j].chave) break;
        a[i] = a[j];
        i = j;
        j = i * 2;
    }
    a[i] = x;
}

void construir(Vetor a, Indice *n) {
    Indice esq;
    esq = *n / 2 + 1;
    while (esq > 1) {
        esq--;
        refazer(esq, *n, a);
    }
}