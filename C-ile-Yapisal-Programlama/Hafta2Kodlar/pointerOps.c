#include <stdio.h>

int main(){
	int i;
	printf("%d\n\n", sizeof(int));
	int digits[10]={0,1,2,3,4,5,6,7,8,9};
	/*for(i=0;i<10;i++){
		*digits+=1;
		*digits+=1;
		*digits+=1;
		printf("%d %p\n",*digits+i, digits+i);
	}*/
	*digits += 3;
	while(digits){
		printf("%d", *digits);
		*digits+=1;
	}
	return 0;
}