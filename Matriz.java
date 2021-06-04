public class Matriz {
    private Integer[][] matriz;

    private Integer calcularDeterminante(Integer[][] matriz) {

        Integer determinante = 0;
        if (matriz.length == 1) {

            determinante = matriz[0][0];
        } else if (matriz.length == 2) {

            determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
        } else if (matriz.length == 3) {

            determinante = matriz[0][0] * matriz[1][1] * matriz[2][2] + matriz[0][1] * matriz[1][2] * matriz[2][0]
                    + matriz[0][2] * matriz[1][0] * matriz[2][1] - matriz[0][2] * matriz[1][1] * matriz[2][0]
                    - matriz[0][0] * matriz[1][2] * matriz[2][1] - matriz[0][1] * matriz[1][0] * matriz[2][2];
        } else {
            Integer[][] aux;
            Integer i_aux, j_aux, linha, coluna, i;

            for (i = 0; i < matriz.length; i++) {
                if (matriz[0][i] != 0) {
                    aux = new Integer[matriz.length - 1][matriz.length - 1];
                    i_aux = 0;
                    j_aux = 0;
                    for (linha = 1; linha < matriz.length; linha++) {
                        for (coluna = 0; coluna < matriz.length; coluna++) {
                            if (coluna != i) {
                                aux[i_aux][j_aux] = matriz[linha][coluna];
                                j_aux++;
                            }
                        }
                        i_aux++;
                        j_aux = 0;
                    }
                    determinante += (int) Math.pow(-1, i) * matriz[0][i] * calcularDeterminante(aux);
                }

            }
        }
        return determinante;
    }
   
    public void setMatriz(Integer[][] matriz) {
        this.matriz = matriz;
    }

    public Integer[][] getMatriz() {
        return this.matriz;
    }

    public Integer getDetermiante() {
        return this.calcularDeterminante(this.matriz);
    }

    public Integer[][] getTransposta() {
        int n = matriz.length;
        Integer[][] matrizT = new Integer[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrizT[i][j] = matriz[j][i];
            }
        }
        return matrizT;
    }

    private Boolean isTypeSuperior(int n) {
        Boolean isTypeSuperior = true;
        // Triangular superior
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (matriz[i][j] != 0)
                    isTypeSuperior = false;

        return isTypeSuperior;
    }

    private Boolean isTypeInferior(int n) {
        Boolean isTypeInferior = true;
        // triangular inferior
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (matriz[i][j] != 0)
                    isTypeInferior = false;
        return isTypeInferior;
    }

    private Boolean isTypeNull(int n) {
        Boolean isTypeNull = true;
        // triangular inferior
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matriz[i][j] != 0)
                    isTypeNull = false;
        return isTypeNull;
    }

    public void WhatTypeMatriz() {
        int n = matriz.length;
        Boolean isTypeSuperior = isTypeSuperior(n), isTypeInferior = isTypeInferior(n), isTypeNull = isTypeNull(n);

        if (isTypeSuperior && isTypeInferior && !isTypeNull) {
            System.out.println("e uma matriz identidade");
            return;
        } else if (isTypeNull) {
            System.out.println("e uma matriz nula");
        } else {
            System.out.println((isTypeInferior ? "e" : "nao e") + " uma matriz triangular superior");
            System.out.println((isTypeSuperior ? "e" : "nao e") + " uma matriz triangular inferior");
        }
    }

    public void isSimetric() {
        Integer [][] novaMatriz= getTransposta();
        Boolean res = true;
        for(int i = 0; i < novaMatriz.length; i++) {
            for(int j = 0; j < novaMatriz.length; j++) {
                if(this.matriz[i][j] != novaMatriz[i][j]) {
                    res = false;
                    break;
                }
            }    
        }

        System.out.println((res ? "e" : "nao e") + " uma matriz simetrica");
    }
}

/*
 * 3 1 3 4 5 2 -3 1 4 2
 */
