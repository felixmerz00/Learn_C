#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[] = "Hallo";
    char s2[10];
    strcpy(s2, s1);
    printf("String1: %s, String2: %s", s1, s2);
    return 0;
}
