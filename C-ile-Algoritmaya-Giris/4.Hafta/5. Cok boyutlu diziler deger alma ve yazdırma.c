#include <stdio.h>

int main()
{
  int dizi[2][3] = {{12,34,22},{11,49,98}};        
  
  for(int i = 0; i < 3; i++)
     {
          for(int j = 0; j < 4; j++)
          {
               printf("Dizi[%d][%d] = ",i,j);
               scanf("%d",&dizi[i][j]);
          }
     }
     for(int i = 0; i < 3; i++)
     {
          for(int j = 0; j <4; j++)
          {
               printf("%d\t",dizi[i][j]);
          }
          printf("\n");
     }
}