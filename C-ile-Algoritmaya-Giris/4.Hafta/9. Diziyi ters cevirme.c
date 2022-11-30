#include <stdio.h>

int main(){
    
int i,n,temp;

printf("dizinin eleman sayisini giriniz:");
scanf("%d",&n);

int dizi[n];


for(i=0;i<n;i++){

printf("dizinin %d. elemanini giriniz:",i+1);
scanf("%d",&dizi[i]);

}

for(i=0;i<n/2;i++){
    temp=dizi[i];
    dizi[i]=dizi[n-1-i];
    dizi[n-1-i]=temp;
}

for(i=0;i<n;i++){
printf("%d ",dizi[i]);
}

 return 0;

}
