#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){
	int sayi1,sayi2,sonuc;
	char op;
	printf("input format: sayi1 operator sayi2\n");
	printf("type '0 x 0' to exit\n");
	while(true){
		scanf("%d %c %d",sayi1,&op,&sayi2);
		switch(op){
			case '+':
				sonuc=sayi1+sayi2;
				break;
			case '-':
				sonuc=sayi1-sayi2;
				break;
			case '*':
				sonuc=sayi1*sayi2;
				break;
			case '/':
				sonuc=sayi1/sayi2;
				break;
			case '%':
				sonuc=sayi1%sayi2;
				break;
			case 'x':
				exit(0);
				break;
			default:
				printf("Hatali islem girisi");
				break;
		}
		printf("%d\n",sonuc);
	}
	
}