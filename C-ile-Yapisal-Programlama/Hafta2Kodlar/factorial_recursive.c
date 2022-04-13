#include <stdio.h>

int find_fact(int);

int main(){
	int n,factorial;
	printf("Bir sayı giriniz:");
	scanf("%d",&n);
	factorial=find_fact(n);
	printf("%d!= %d",n,factorial);
	return 0;
}


int find_fact(int say){
	if(say-1>=1){
		return say*find_fact(say-1); 
	}else{
		return 1;
	}
}