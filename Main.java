import java.util.*;

public class Main {
    public static void main(String[] args) {
        Matriz novamatriz = new Matriz();
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        Integer[][] matriz = new Integer[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matriz[i][j] = input.nextInt();
            }
        }
        novamatriz.setMatriz(matriz);
        System.out.println(novamatriz.getDetermiante());
        Integer[][] matrizT = novamatriz.getTransposta();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.printf("%d ", matrizT[i][j]);
            }
            System.out.printf("\n");
        }
        novamatriz.WhatTypeMatriz();
        novamatriz.isSimetric();
        input.close();
    }
}
