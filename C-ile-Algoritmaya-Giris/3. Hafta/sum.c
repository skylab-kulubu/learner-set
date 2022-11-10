//
//  main.c
//  loop_ornekler
//
//  Created by burcupc on 8.11.2022.
//

#include <stdio.h>

int sum(int sayi){
	int i,toplam1=0;
	for( i=1 ;i<=sayi;i++){
    	printf("toplam: %d, i: %d \n",toplam1,i);
        toplam1=i+toplam1;
    }
    return toplam1;
}

int main(int argc, const char * argv[]) {
    int sayi, toplam=0;
    int i;
    printf("Bir sayi giriniz:");
    scanf("%d",&sayi);
    
    toplam=sum(sayi);
    
    printf("toplam:%d\n",toplam);
    return 0;
}
