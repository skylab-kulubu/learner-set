//
//  main.c
//  sorting
//
//  Created by burcupc on 28.11.2022.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n,dizi[n],i,j,tmp;
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&dizi[i]);
    }
    
    printf("dizi:\n");
    for(i=0;i<n;i++){
        printf("%d ",dizi[i]);
    }
    
    
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (dizi[j] > dizi[j + 1]){
                    tmp=dizi[j];
                    dizi[j]=dizi[j+1];
                    dizi[j+1]=tmp;
            }
        }
    }
    
    
    printf("\nsıralamadan sonra dizi:\n");
    for(i=0;i<n;i++){
        printf("%d ",dizi[i]);
    }
    printf("\n");
    return 0;
}
