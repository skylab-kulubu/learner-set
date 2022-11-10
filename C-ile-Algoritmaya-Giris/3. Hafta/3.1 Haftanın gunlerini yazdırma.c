#include <stdio.h>
int main()
{
    int hafta;
    
    printf("Haftanin kacinci gunu(1-7): ");
    scanf("%d", &hafta);
    
    switch(hafta)
    {
        case 1:{
			
            printf("Pazartesi");
			}
     //       break;
        case 2: 
            printf("Sali");
            break;
        case 3: 
            printf("Carsamba");
            break;
        case 4: 
            printf("Persembe");
            break;
        case 5: 
            printf("Cuma");
            break;
        case 6: 
            printf("Cumartesi");
            break;
        case 7: 
            printf("Pazar");
            break;
        default: 
            printf("Gecersiz sayi. Lutfen aralikta bir sayi giriniz 1-7.");
    }

    return 0;
}
