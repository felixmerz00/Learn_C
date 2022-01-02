#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%d", calculate(1, 2, 3, 4));
}

int calculate(int a, int b, int c, int d)
{
    int out = a + b + c - d;
    return out;
}
