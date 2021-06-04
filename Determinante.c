#include <stdio.h>
#include <stdlib.h>
#include "Determinante.h"

int main() {
    int matriz[MAX][MAX];
    int orden;

    scanf("%d", &orden);

    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Determinante = %d\n", determinante(matriz, orden));
    return 0;
}
//gcc calcdeterminante.c determinante.c -o Determinante.exe && Determinante.exe