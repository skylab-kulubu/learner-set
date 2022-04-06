#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ***matrix;
    
    int num_rows, num_words, num_letters;
    int i, j;
    
    printf("Enter the number of rows: ");
    scanf("%i", &num_rows);
    
    printf("Enter the number of words in each row: ");
    scanf("%i", &num_words);
    
    printf("Enter the number of letters in each word: ");
    scanf("%i", &num_letters);
    
    matrix = (char***)malloc(num_rows * sizeof(char**));
    
    for (i = 0; i < num_rows; i++)
    {
        matrix[i] = (char**)malloc(num_words * sizeof(char*));
        for (j = 0; j < num_words; j++)
        {
            matrix[i][j] = (char*)malloc(num_letters * sizeof(char));
            printf("Enter a word: ");
            scanf("%s", matrix[i][j]);
        }
    }

    printf("\nMatrix: \n\t\t");
    
    for (i = 0; i < num_rows; i++)
    {
        for (j = 0; j < num_words; j++)
        {
            printf("%s ", matrix[i][j]);
        }
        printf("\n\t\t");
    } 
    
    return 0;
}
