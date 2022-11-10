#include <stdio.h>
int main()
{
    int num1, num2;
 
    printf("iki sayi girniz: ");
    scanf("%d%d", &num1, &num2);
    /* 1. sayi buyuk ise */
    if(num1 > num2)
    {
        printf("Ilk sayi: %d buyuktur\n ", num1);        
    }
	else 
    {
        printf("Ikinci sayi: %d buyuktur", num2);
    }
    if(num1 == num2)
    	printf("Iki sayi esittir."); printf("Iki sayi esittiwqer.");
        
        
        
    return 0;
}
