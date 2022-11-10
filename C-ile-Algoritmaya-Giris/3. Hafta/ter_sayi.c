//
//  main.c
//  sayi_tersi
//
//  Created by burcupc on 8.11.2022.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int sayi,n,b=0;
    
    printf("Bir sayi giriniz:");
    scanf("%d",&sayi);
    
    n=sayi;
    
    while(sayi>0){
        b=(b*10)+(sayi%10);
        sayi/=10;             
    }
    
    printf("%d sayisinin tersi %d\n",n,b);
    return 0;
}
