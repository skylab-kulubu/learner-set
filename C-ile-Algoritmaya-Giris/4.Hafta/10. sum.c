//
//  main.c
//  diziler
//
//  Created by burcupc on 29.11.2022.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i,N,toplam=0;
    
    printf("dizinin boyutunu giriniz:");
    scanf("%d",&N);
    
    int arr[N];
    
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<N;i++){
        if(arr[i]>0){
            toplam+=arr[i];
        }
    }
    
    printf("%d\n",toplam);
    return 0;
}
