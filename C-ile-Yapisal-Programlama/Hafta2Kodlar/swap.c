#include <stdio.h>

void swap(int*, int*);

int main()
{
	int sayi1 = 5;
	int sayi2 = 7;

	printf("sayi1=%d sayi2=%d\n\n", sayi1, sayi2);

	swap(&sayi1, &sayi2);

	printf("sayi1=%d sayi2=%d\n", sayi1, sayi2);


	return 0;
}

void swap(int* a, int* b){

	printf("fonksiyon icinden: sayi1=%d sayi2=%d\n", *a, *b);

	int tmp = *b;
	*b = *a;
	*a = tmp;

	printf("fonksiyon icinden: sayi1=%d sayi2=%d\n\n", *a, *b);

	return;
}