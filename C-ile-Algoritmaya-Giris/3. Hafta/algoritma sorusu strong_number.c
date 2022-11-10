//
//  main.c
//  strong_number
//
//  Created by burcupc on 8.11.2022.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int sayi,b,n,sonuc=0,fakt=1;
    
    printf("Bir sayi giriniz:");
    scanf("%d",&sayi);
    
    n=sayi;
    
    while(sayi!=0){
        b=sayi%10;
        if(b >= 0){
            for(int i=1;i<=b;i++){
                fakt *= i;
            }
        }
        sonuc+=fakt;
        sayi/=10;
    }
    
    if(sonuc==n){
        printf("%d bir guclu sayi\n",n);
    }
    else{
        printf("%d bir guclu sayi degil\n",n);
    }
    return 0;
}
