#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dest[20]="Hello";
    char src[20]="World";
    strncat(dest,src,20);
    printf("%s\n",dest);
}
