#include <bits/stdc++.h>
int main() {
    int x, y, cont;
    printf("entre com os dados:");
    scanf("%d", &x);
    scanf("%d", &y);
    cont = (x * x) + (2 * x + y) + (y * y);
    printf("resultado: %d", cont);
    return 0;
}
