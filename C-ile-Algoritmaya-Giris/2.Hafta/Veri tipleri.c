#include <stdio.h>

int main(int argc, char const *argv[])
{
    char harf = 'K';
    char harf2 = 65;

    printf("Harf: %c \nHarf: %c\n",harf,harf2);
    
    short sayi0 = 1000;   // -32768 <= sayi0 <= 32767  2byte

    printf("Sayı0: %hd\n",sayi0);
    sayi0 = 32768;
    printf("Sayı0: %hd\n",sayi0);

    int sayi1=214783647; 
    printf("Sayı0: %d\n",sayi1);

    long sayi4;
    float sayi2;
    double sayi3;

    
    sayi1 = 5;


    return 0;
}
