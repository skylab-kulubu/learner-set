#include <stdio.h>

int main()
{
	int var=100;
	int *point=&var;

	printf("%d\n%p\n%d\n",var,&var,*point);

	return 0;
}