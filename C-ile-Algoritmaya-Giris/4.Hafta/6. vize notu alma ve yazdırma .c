#include <stdio.h>
 
int main()
{
    int dizi[3][2];  
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j+=2)
        {
            printf("%d. Ogrencinin vize notunu giriniz: ",i+1);
            scanf("%d",&dizi[i][j]);
            printf("%d. Ogrencinin final notunu giriniz: ",i+1);
            scanf("%d",&dizi[i][j+1]);
        }
    }
 
    printf("\nOgrenci No\t Vize Puani\t Final Notu");
 
    for(int i = 0; i < 3; i++)
    {
        printf("\nNO : %d\t", i+1);
        for(int j = 0; j < 2; j+=2)
        {
            printf("\t\t%d",dizi[i][j]);
            printf("\t\t%d",dizi[i][j+1]);
        }
        
    }
}