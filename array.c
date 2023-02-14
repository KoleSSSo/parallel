#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <malloc.h>
#include <stdio.h>
#include <math.h>

#define TYPE float
#define ABSBASE 10000000

int main() {
	TYPE* a = (TYPE*)malloc(ABSBASE * sizeof(TYPE));
	TYPE sum = 0;
#pragma acc kernels
	for (int i = 1; i <= ABSBASE; i++) {
		a[i] = sin(i * M_PI * 2 / ABSBASE);
	}
#pragma acc kernels 
	for (int i = 1; i <= ABSBASE; i++) {
		sum += a[i];
		}
	return 0;
}
