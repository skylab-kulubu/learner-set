#include <stdio.h>

int main()
{
     int dizi[5];
     int toplam = 0;
     int i;
     
     for( i = 0; i < 5; )
     {
        printf("%d. sayiyi giriniz:",i+1);
        scanf("%d",&dizi[i]);
        toplam += dizi[i++];
        
     }
     printf("Dizi elemanlarinin toplami = %d",toplam);
}
