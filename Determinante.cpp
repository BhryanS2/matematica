#include <bits/stdc++.h>
using namespace std;

const int MAX = 10e3;
int n, m;
int M[MAX][MAX];

int sarrus(int* res) {
    *res = 0;
    *res = (M[0][0] * M[1][1] * M[2][2]) + (M[0][1] * M[1][2] * M[2][0]) + (M[0][2] * M[1][0] * M[2][1]);
    *res = *res + (-M[0][2] * M[1][1] * M[2][0]) + (-M[0][0] * M[1][2] * M[2][1]) + (-M[0][1] * M[1][0] * M[2][2]);
    return *res;
}

int MenorComplementar(int* l, int* c) {
    int diagonal_P = 1, diagonal_S = 1;
    int newMatrix[n - 1][m - 1], contX = 0, contY = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            newMatrix[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i != *l && j != *c) newMatrix[contX][contY] = M[i][j];

            if (newMatrix[contX][contY] != 0) contY++;

            if (contY == 2) {
                contY = 0;
                contX++;
            }
        }
    }
    for (i = 0; i < n - 1; i++) diagonal_P *= newMatrix[i][i];

    for (i = 0;i < n - 1;i++)
        for (j = 0;j < m - 1;j++)
            if ((i + j) == ((n - 1) - 1)) diagonal_S *= newMatrix[i][j];

    return diagonal_P - diagonal_S;
}

int Cofator(int* i, int* j, int* res) {
    *res = 0;
    *res = pow(-1, *i + *j) * MenorComplementar(i, j);
    return *res;
}

int determinante(int* i, int* j, int* res) {
    res = (M[0][*j] * Cofator(i, j, res)) + res;
    return *res;
}

int main() {
    int i, j, res = 0;

    cout << "entre com o tamanho da matriz\n";
    cin >> n >> m;

    for (i = 0; i < n; i++) for (j = 0; j < m; j++) cin >> M[i][j];

    if (n == 3 && m == 3) cout << sarrus(&res);
    else {
        for (i = 0; i < n; i++) for (j = 0; j < m; j++) res = determinante(&i, &j, &res);
        cout << res << endl;
    }
    return 0;
}