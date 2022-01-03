#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    The following code creates a file, writes the given text and closes the file.
    */
    FILE * fpointer = fopen("employees.txt", "w");
    fprintf(fpointer, "Jim: Salesman\nPam: Receptionist\nOscar: Accounting\n");
    fclose(fpointer);
    /*
    The following code reopens the file, appends the given text and closes the file.
    */
    FILE * fpointer2 = fopen("employees.txt", "a");
    fprintf(fpointer2, "Toby: HR");
    fclose(fpointer2);
    /*
    The following code reopens the file, separately reads and prints the first two
    lines and closes the file.
    */
    FILE * fpointer3 = fopen("employees.txt", "r");
    char line[255];
    fgets(line, 255, fpointer3);
    printf("%s", line);
    fgets(line, 255, fpointer3);
    printf("%s", line);
    fclose(fpointer3);
}
