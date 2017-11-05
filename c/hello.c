/*
 * hello.c
 *
 *  Created on: 26.10.2017
 *  Author: RStyle
 */
#include <stdio.h>
#define N 2

void vorlesung2Stunden() {
	double i1 = -1;

	while(i1 != 0) {
		scanf("%lf", &i1);
		if(i1 > 0) {
			printf("%lf Vorlesungen in Stunden: %lf \n", i1, i1/4*3);
		}
	}
}

void swap(int* a,int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void timeConverter(int* s, int* m, int* h, int* d) {
	*m += *s / 60;
	*h += *m / 60;
	*d += *h / 24;
	*s = *s % 60;
	*m = *m % 60;
	*h = *h % 24;
}

void getMatrix(int m[N][N]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("Wert Position [%d][%d]:", i, j);
			fflush(stdout);
			scanf("%d", &m[i][j]);
		}
	}
}


int main() {

	// vorlesung2Stunden();
	//int i1 = 1;
	//int i2 = 4;
	//swap(&i1, &i2);
	//printf("i1: %d; i2: %d\n", i1, i2);

//	int s = 40333, m = 0, h = 0, d = 0;
//	printf("Days: %d, Hours: %d, Minutes: %d, Seconds:%d\n", d, h, m, s);
//	timeConverter(&s, &m, &h, &d);
//	printf("Days: %d, Hours: %d, Minutes: %d, Seconds:%d\n", d, h, m, s);

	int m1[N][N];
	getMatrix(m1);
	printf("%d, %d, %d, %d", m1[0][0], m1[0][1], m1[1][0], m1[1][1]);

	return 0;
}
