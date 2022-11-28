#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(){
	
	int N,i=0,yas,a=10,k,m,b,c,n;
	int yasAraliklari[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	printf("kisi sayisi girin\n");
	scanf("%d",&N);
	int yaslar[N];
	while(i<N){
		printf("%d. kisinin yasini girin\n",i+1);
		scanf("%d",&yaslar[i]);
		for(k=0;k<12;k++){
			if(yaslar[i]>=a){
				a=a+10;
			}
			else{
				yasAraliklari[k]+=1;
				k=12;
				a=10;
			}
		}
		i=i+1;
	}
	c=0;
	b=9;
	for(m=0;m<12;m++){
		printf("%d - %d yas arasinda %d kisi vardir\n",c,b,yasAraliklari[m]);
		c=c+10;
		b=b+10;
	}
}