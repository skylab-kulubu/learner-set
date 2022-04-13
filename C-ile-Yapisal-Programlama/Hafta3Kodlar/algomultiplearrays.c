#include<stdio.h>
#define max 50

int main (){
int adizi[max][max],bdizi[max][max],sonuc[max][max];
int arows,acolumns,brows,bcolumns ,sum=0;
int i,j,k;

printf("a dizisinin satir ve sutun sayisini giriniz:\n");
scanf("%d %d", &arows,&acolumns);

for(i=0;i<arows;i++){
	for(j=0;j<acolumns;j++){
		printf("dizinin elemanlarini giriniz:");
		scanf("%d",&adizi[i][j]);
	}
}

printf("b dizisinin satir ve sutun sayisini giriniz:\n");
scanf("%d %d", &brows,&bcolumns);
if(brows!=acolumns){
	printf("!iki dizinin satir ve sutun sayilari esit olmali!");
}
else{
	printf("dizinin elemanlarini giriniz:");
	for(i=0;i<brows;i++){
	    for(j=0;j<bcolumns;j++){
		    
		    scanf("%d",&bdizi[i][j]);
	}
}
}
printf("\n");
for(i=0;i<arows;i++){
	for(j=0;j<bcolumns;j++){
		for(k=0;k<brows;k++){
			sum += adizi[i][k] * bdizi[k][j];
		}
		sonuc[i][j]=sum;
		sum=0;
	}
}
printf("carpimlarin sonucu:\n");
for(i=0;i<arows;i++){
	printf("\n");
	for(j=0;j<bcolumns;j++){
		printf("%d ",sonuc[i][j]);
	}
	printf("\n");
}	

return 0;
}
