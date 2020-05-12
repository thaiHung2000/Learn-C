#include <stdio.h>
/*
Function is used to print sum of row and the descending row
Input: n: the number of elements of row
       ptr: row which want to be executed
Output: print sum of row and the descending row
*/
void sortDesAndSum( int n, int *ptr );
int main()
{
    int size1,size2;
    /* enter the number of elements of row 1*/
    scanf("%d",&size1);
     /* enter the number of elements of row 2*/
    scanf("%d", &size2);
    int *ptr1,*ptr2;
    ptr1 = (int*)malloc(size1*sizeof(int));
    ptr2 = (int*)malloc(size2*sizeof(int));
    /* Enter element of row 1*/
    for(int i = 0 ; i < size1; i++)
    {
        scanf("%d", (ptr1 + i));
    }
     /* Enter element of row 2*/
    for(int i = 0 ; i < size2; i++)
    {
        scanf("%d", (ptr2 + i));
    }
    
    sortDesAndSum(size1, ptr1);
    sortDesAndSum(size2, ptr2);
}


void sortDesAndSum( int n, int *ptr )
{
    for( int i = 0 ; i < n ; i ++ )
    {
        for( int j = 0 ; j < n - 1  ; j ++ )
        {
            if( *(ptr + j) < *(ptr + j+1 ))
            {
                int temp = *(ptr + j);
                *(ptr+ j) = *(ptr + j +1 );
                *(ptr + j +1 )= temp;
            }
        }
    }
    int sum = 0;
    for(int i = 0 ; i < n ; i++ )
    {
        sum+= *(ptr + i);
        printf("%d ", *(ptr + i));
    }
    printf("\n%d\n", sum);
    
    
}

