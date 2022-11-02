#include <stdio.h>

int main()
{
    float uzunluk, genislik, cevre;

    /*
     * Boyunu ve genisligini girin
     */
    printf("Dikdortgenin boyu: ");
    scanf("%f", &uzunluk);
    printf("Dikdortgenin uzunlugu: ");
    scanf("%f", &genislik);

    /* Dikdortgenin cevresi */
    cevre = 2 * (uzunluk + genislik);

    /* cevresini yazdır */
    printf("Dikdortgenin cevresi = %f birim ", cevre);

    return 0;
}