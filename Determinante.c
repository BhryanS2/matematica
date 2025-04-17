#include <stdio.h>
#include <stdlib.h>
#include "Determinante.h"

int main() {
    int matriz[MAX][MAX];
    int ordem;

    scanf("%d", &ordem);

    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Determinante = %d\n", determinante(matriz, ordem));
    return 0;
}
//gcc calcdeterminante.c determinante.c -o Determinante.exe && Determinante.exe
