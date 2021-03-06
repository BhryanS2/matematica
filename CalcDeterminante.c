#include "Determinante.h"
#include <math.h>

int determinante(int matriz[][MAX], int orden) {
    int det = 0.0;

    if (orden == 1)  det = matriz[0][0];
    else {
        for (int j = 0; j < orden; j++) {
            det = det + matriz[0][j] * Cofator(matriz, orden, 0, j);
        }
    }

    return det;
}


int Cofator(int matriz[][MAX], int orden, int EixoX, int EixoY) {
    int submatriz[MAX][MAX];
    int n = orden - 1;

    int x = 0;
    int y = 0;
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            if (i != EixoX && j != EixoY) {
                submatriz[x][y] = matriz[i][j];
                y++;
                if (y >= n) {
                    x++;
                    y = 0;
                }
            }
        }
    }

    return pow(-1.0, EixoX + EixoY) * determinante(submatriz, n);
}