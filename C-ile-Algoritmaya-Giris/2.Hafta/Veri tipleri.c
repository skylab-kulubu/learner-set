#include <stdio.h>

int main(int argc, char const *argv[])
{
    char harf = 'K';
    char harf2 = 65;

    printf("Harf: %c \nHarf: %c\n",harf,harf2);
    
    short sayı0 = 1000;   // -32768 <= sayı0 <= 32767  2byte

    printf("Sayı0: %hd\n",sayı0);
    sayı0 = 32768;
    printf("Sayı0: %hd\n",sayı0);

    int sayı1=214783647; 
    printf("Sayı0: %d\n",sayı1);

    long sayı4;
    float sayı2;
    double sayı3;

    
    sayı1 = 5;


    return 0;
}
