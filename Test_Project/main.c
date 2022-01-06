#include <stdio.h>

const char* myName() {
    char *name = "Flavio";
    return name;
}

int main(void) {
    char * bla = myName();
    printf("%s", bla);
}
