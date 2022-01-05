#include <stdio.h>

#define TRUE 1
#define FALSE 0

void test(int expected, int actual, const char* testName){
    if (expected == actual){
        printf("\n%s PASSED", testName);
    }
    else{
        printf("\n%s FAILED expected: %d actual: %d", testName, expected, actual);
    }

}
