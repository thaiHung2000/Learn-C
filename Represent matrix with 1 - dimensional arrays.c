#include <stdio.h>
int main()
{
    int row, column;
    /* input the number of row of matrix*/
    scanf("%d", &row);
    /* input the number of column of matrix*/
    scanf("%d", &column);
    int *arr[row];
    /*input matrix*/
    for(int i = 0 ; i < row ; i ++)
    {
        arr[i] = (int*)malloc(cot*sizeof(int));
        
        for(int j = 0 ; j < column ; j++)
        {
            scanf("%d", arr[i]+ j);
        }
    }
    /*output matrix */
    for(int i = 0 ; i < row ; i ++)
    {
        
        for(int j = 0 ; j < column ; j++)
        {
            printf("%d ", *(arr[i]+ j));
        }
        printf("\n");
    }
}
