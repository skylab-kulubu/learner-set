//
//  main.c
//  if_else_hesapmak
//
//  Created by burcupc on 7.11.2022.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int sayi1, sayi2, sonuc=0;
    char islem;
    
    printf("iki sayi giriniz: ");
    scanf("%d %d",&sayi1,&sayi2);
    
    printf("Hangi islemi yapmak istiyorsunuz?: ");
    scanf(" %c",&islem);
    
    if(islem=='+'){
        sonuc=sayi1 + sayi2;
        printf("%d %c %d = %d\n",sayi1,islem,sayi2,sonuc);
    }
    else if(islem=='-'){
        sonuc=sayi1 - sayi2;
        printf("%d %c %d = %d\n",sayi1,islem,sayi2,sonuc);
    }
    else if(islem=='*'){
        sonuc=sayi1 * sayi2;
        printf("%d %c %d = %d\n",sayi1,islem,sayi2,sonuc);
    }
    else if(islem=='/'){
        sonuc=sayi1 / sayi2;
        printf("%d %c %d = %d\n",sayi1,islem,sayi2,sonuc);
    }
    else{
        printf("gecerli bir islem giriniz.");
    }
    
    
    return 0;
}
