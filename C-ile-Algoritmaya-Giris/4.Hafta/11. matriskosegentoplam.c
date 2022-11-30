#include <stdio.h>

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int n,row,col,x,sum=0;
    
    printf("enter the n value:");
    scanf("%d",&n);
    
    int a[n][n];
    
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            scanf("%d",&a[row][col]);
        }
    }
    
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
    if(row==col){
        sum += a[row][col];
    }
        }
    }
    
    printf("\n%d",sum);
    
    
}
