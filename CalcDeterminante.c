#include "Determinante.h"
#include <math.h>

int determinante(int matriz[][MAX], int ordem) {
    int det = 0.0;

    if (ordem == 1)  det = matriz[0][0];
    else {
        for (int j = 0; j < ordem; j++) {
            det = det + matriz[0][j] * Cofator(matriz, ordem, 0, j);
        }
    }

    return det;
}


int Cofator(int matriz[][MAX], int ordem, int EixoX, int EixoY) {
    int submatriz[MAX][MAX];
    int n = ordem - 1;

    int x = 0;
    int y = 0;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
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
