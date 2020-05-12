#include <stdio.h>
/*
Function is used to switch from decimal to binary
Input: decimal
Output: binary
*/
char switchToBinary (float var );

/*
Function is used to switch from binary to decimal
Input: binary
Output: decimal
*/
char convertToDecimal (char var );

int main()
{
    char binary = 0;
    /* input score average*/
    float scoreAverage;
    scanf("%f", &scoreAverage);
    binary = switchToBinary(scoreAverage);
    printf("%d\n", binary);
    char c = convertToDecimal(binary);
    int a = c % 10;
    printf("%d.%d",c / 10, a);
    
}


char switchToBinary ( float var )
{
    char a = var * 10;
    char b = a / 10;
    char c = a % 10;
    return b * 16 + c;
}


char convertToDecimal ( char var )
{
    char a = var >> 4;
    char b = var << 4;
    b = b >> 4;
    return a*10 + b;
}
