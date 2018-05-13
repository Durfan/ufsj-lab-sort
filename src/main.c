#include <stdio.h>
#include <string.h>
#include "src/ordena.h"

void insereSTR (Vetor a, char *str) {
    int i=1;
    while ( *str != '\0' ) {
        a[i].chave = *str;
        str++;
        i++;
    }
}

void printVETOR (Vetor a, int n) {
    int i;
    for (i=1; i<=n; i++) {
        printf("%c\n", a[i].chave);
    }
}

int main() {
    char str[] = "ORDENA";
    int n = strlen(str);
    Vetor A;

    printf("%s\n", str);
    printf("%d\n", n);

    insereSTR(A,str);
    
    printVETOR(A,n);
    printf("\n");
    n = 6;
    selecao(A,&n);
    printVETOR(A,n);

    return 0;
}