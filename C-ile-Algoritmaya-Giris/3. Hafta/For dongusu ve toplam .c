#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sayac,sayı=7,toplam=0;

    while (sayac <= sayı)
    {
        toplam += sayac;
        sayac++;
    }
    
    for ( sayac = 2; sayac < sayı; sayac++){
        toplam += sayac;
    }
    

    return 0;
}
