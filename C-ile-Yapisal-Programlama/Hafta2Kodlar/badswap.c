#include <stdio.h>


void swap(int num1,int num2){
	int tmp=num1;
	num1=num2;
	num2=tmp;
}

int main()
{
	int x=5,y=7;
	printf("%d-%d\n",x,y);
	swap(x,y);
	printf("%d-%d\n",x,y);
	return 0;
}