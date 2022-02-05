#include<stdio.h>

int main()
{
    // why does this work??
    int b[] = {5, 4, 3, 2};
    b[4] = 5;
    printf("%d\n", b[4]);
}