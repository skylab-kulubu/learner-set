#include <stdio.h>

int main()
{
  int dizi[2][3];// = {{12,34,22},{11,49,98}};        
  int i,j;
  
  for( i = 0; i < 2; i++)
     {
          for( j = 0; j < 3; j++)
          {
               printf("Dizi[%d][%d] = ",i,j);
               scanf("%d",&dizi[i][j]);
          }
     }
     for(i = 0; i < 2; i++)
     {
          for(j = 0; j <3; j++)
          {
               printf("%d\t",dizi[i][j]);
          }
          printf("\n");
     }
}
