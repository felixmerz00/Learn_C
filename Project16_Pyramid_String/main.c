#include <stdio.h>
#include <stdlib.h>

char * generate_line(int number_of_ints);
void generate_pyramid(int height);

int main()
{
    generate_pyramid(5);
    return 0;
}

void generate_pyramid(int height)
{
    int h = height;
    /*char *pLine2;
    pLine2 = generate_line(9);
    printf("%s\n", pLine2);*/

    /*create a string that collects all the lines*/

    for(int i = 1; i <= height; i++){
        char *pLine;
        pLine = generate_line(i);
        printf("%s\n", pLine);
    }

    /*make a loop for the lower half of the pyramid*/

}

/*takes the last integer of the line as input parameter and returns a pointer to the string containing the line*/
char * generate_line(int number_of_ints)
{
    char s[number_of_ints*2+1];
    s[0] = '\0';
    char suffix[4];
    for(int i = 1; i <= number_of_ints; i++){
        snprintf(suffix, number_of_ints, "%d*", i);
        strncat(s, suffix, 2);
        /*printf("%s\n", s);*/
    }
    int length = strlen(s);
    char *pS_out;
    pS_out = (char *) malloc(length*sizeof(char));
    pS_out[0] = '\0';
    if(number_of_ints > 1){
        strncpy(pS_out, s, length-1);
        pS_out[length-1] = '\0';
    }
    else{
        strncpy(pS_out, s, length);
        pS_out[length] = '\0';
    }
    return pS_out;
}
