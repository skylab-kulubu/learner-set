#include <stdio.h>

int main()
{
    int num1, num2;
    int toplam, fark, carpma, mod;
    float bolum;

    /*
     * iki tane sayı girdisi yapın
     */
    printf("Enter any two numbers: ");
    scanf("%d%d", &num1, &num2);

    /*
     * Butun oparatorler
     */ 
    toplam = num1 + num2;
    fark = num1 - num2;
    carpma = num1 * num2;
    bolum = (float)num1 / num2;
    mod = num1 % num2;

    /*
     * butun islemleri yazdır
     */
    printf("toplam = %d\n", toplam);
    printf("fark = %d\n", fark);
    printf("carpma = %d\n", carpma);
    printf("bolum = %f\n", bolum);
    printf("mod = %d", mod);

    return 0; 
}
