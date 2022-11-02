#include <stdio.h>
int main()
{
    int num1, num2; 
	float sum;
    printf("Enter any one number : ");
    scanf("%d", &num1);
    
    num1= num1+1;
    printf("%d\n",num1);
    
    num1++;
    printf("%d\n",num1);
    
    num1+=1;
    printf("%d",num1);
    
    //printf("Sum of %d and %d = \n%f", num1, num2, sum);
    
    return 0;
}
