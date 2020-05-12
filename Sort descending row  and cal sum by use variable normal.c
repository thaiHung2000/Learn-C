#include <stdio.h>
/*
 Function is used to print sum of row and the descending row
 Input: n: the number of elements of row
        arr[n]: row which want to be executed
 Output: print sum of row and the descending row
 */
void sortDesAndSum( int n, int arr[n] );

int main()
{
    int size1,size2;
    /* Enter the number of elements of row 1*/
    scanf("%d",&size1);
    /* Enter the number of elements of row 2*/
    scanf("%d", &size2);
    int day1[size1], day2[size2];
    /* Enter element of row 1*/
    for(int i = 0 ; i < size1; i++)
    {
        scanf("%d", &day1[i]);
    }
    /* Enter element of row 2*/
    for(int i = 0 ; i < size2; i++)
    {
        scanf("%d", &day2[i]);
    }
    
    sortDesAndSum(size1, day1);
    
    sortDesAndSum(size2, day2);
}

void sortDesAndSum( int n, int arr[n] )
{
    for( int i = 0 ; i < n ; i ++ )
    {
        for( int j = 0 ; j < n - 1  ; j ++ )
        {
            if( arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int sum = 0;
    for(int i = 0 ; i < n ; i++ )
    {
        sum+= arr[i];
        printf("%d ", arr[i]);
    }
    printf("\n%d\n", sum);
    
    
}

