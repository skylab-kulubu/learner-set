#include <stdio.h>
#include <stdlib.h>

int puan(int **matris,int i,int n){
    int count=0,a;
    for(i=0;i<n;i++){
        if(matris[i][a]!=0){
            count++;
        }
    }
    for(i=0;i<n;i++){
        if(matris[a][i]!=0){
            count+=(n-matris[a][i]+1);
        }
    }
  
    return count;
    
}

void sonuc ( puanlar,int n){
	int max=0, max2=0,max3=0;
	int i;
	
for(i=0;i<n;i++){
	if(*(puanlar+i)>max){
		max=*(puanlar+i);
	}
	for(i=0;i<n;i++){
	if(*(puanlar+i)>max2 && *(puanlar+i)<max){
		max2=*(puanlar+i);
	}for(i=0;i<n;i++){
	if(*(puanlar+i)>max3 && *(puanlar+i)<max2){
		max3=*(puanlar+i);
	}
	printf("%d %d %d",max,max2,max3);
}	
	
}
int main()
{
    int **matris,*puanlar;
    int satir, kolon;
    int s, k,j;
    int i,n;
    
    scanf("%d",&n);
    
    matris = (int **) calloc(n, sizeof(int));

   
    for(i = 0; i < n; i++)
    matris[i] = (int *) calloc(n, sizeof(int));

    
    for(s = 0; s < n; s++){
	for(k = 0; k < n; k++) {
        printf("Matrisin elemani girin: matris[%d][%d] = ", s, k);
        scanf("%d", &(matris[s][k]));
        
        for(i=0;i<n;i++){
         *(puanlar + i) = puan(**matris,i,n);
        }
    }
}
        
  ;
    sonuc(puanlar,n);
    return 0;
}
