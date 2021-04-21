#include <bits/stdc++.h>
int main() {
    float n1, n2, n3, n4, media;
    printf("entre com as notas:");
    scanf("%f", &n1);
    scanf("%f", &n2);
    scanf("%f", &n3);
    scanf("%f", &n4);
    media = (n1 * 1 + n2 * 2 + n3 * 3 + n4 * 4) / (1 + 2 + 3 + 4);
    printf("resultado:%f", media);
    return 0;
}
