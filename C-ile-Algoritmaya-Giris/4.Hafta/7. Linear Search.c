//
//  main.c
//  linear_search
//
//  Created by burcupc on 29.11.2022.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i,N,x;
    
    printf("Dizinin boyutunu giriniz:");
    scanf("%d",&N);
    
    int arr[N];
    
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("aramak istediginiz elemani giriniz:");
    scanf("%d",&x);
    
    
    for (i = 0; i < N; i++){
        if (arr[i] == x){
                printf("%d\n",i);
        }
    }

    return 0;
}
