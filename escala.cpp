#include<bits/stdc++.h>
int main() {
	int dr;
	float dm, e;
	printf("coloque a distancia real: ");
	scanf("%d", &dr);
	printf("entre com a distancia do mapa: ");
	scanf("%f", &dm);
	e = (dr * 100000) / dm;
	printf("sua escala eh %f", e);


	return 0;
}
