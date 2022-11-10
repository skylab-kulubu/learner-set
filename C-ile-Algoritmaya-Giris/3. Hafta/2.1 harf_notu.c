//
//  main.c
//  harfnotu
//
//  Created by burcupc on 8.11.2022.
//

#include <stdio.h>

int main() {
    int vize1,vize2,final,son_not;
    printf("1. vize notunuzu giriniz:");
    scanf("%d",&vize1);
    
    printf("2. vize notunuzu giriniz:");
    scanf("%d",&vize2);
    
    printf("Final notunuzu giriniz:");
    scanf("%d",&final);
    
    son_not= (vize1)*3/10 + (vize2)*3/10 + (final)*4/10;  
    
    printf("Notunuz:%d\n",son_not);
    
    if(son_not>=90){
        printf("AA\n");
    }
    else if(son_not<=89 && son_not>=80){
        printf("BA\n");
    }
    else if(son_not<=79 && son_not>=70){
        printf("BB\n");
    }
    else if(son_not<=69 && son_not>=60){
        printf("CB\n");
    }
    else if(son_not<=59 && son_not>=50){
        printf("CC\n");
    }
    else if(son_not<=49 && son_not>=40){
        printf("DC\n");
    }
    else if (son_not<=39 && son_not>=30){
        printf("DD\n");
    }
    else if (son_not<=29 && son_not>=20){
        printf("FD\n");
    }
    else{
        printf("FF\n");
    }
    printf("bitti");
    
    
    return 0;
}
