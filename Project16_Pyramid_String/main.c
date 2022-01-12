#include <stdio.h>
#include <stdlib.h>

char * generate_line(int number_of_ints);
void generate_pyramid(int height);

int main()
{
    generate_pyramid(9);
    return 0;
}

/*creates a pyramid string, maximum pyramid height is 9*/
void generate_pyramid(int height)
{
    int h = height;

    /*create a string that collects all the lines*/
    int size = pow(h,2)*2;
    char pyramid[size];
    pyramid[0]='\0';

    /*loop for the upper half of the pyramid*/
    for(int i = 1; i <= h; i++){
        char *pLine;
        pLine = generate_line(i);
        strncat(pyramid, pLine, h*2);
    }

    /*loop for the lower half of the pyramid*/
    for(int i = h-1; i > 0; i--){
        char *pLine;
        pLine = generate_line(i);
        strncat(pyramid, pLine, h*2);
    }
    printf("%s\n", pyramid);

}

/*create a string in the form of:
"1*2*3*...*number_of_ints\n\0"
and return its pointer*/
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
    pS_out = (char *) malloc(length*sizeof(char)+1);
    pS_out[0] = '\0';
    if(number_of_ints > 1){
        strncpy(pS_out, s, length-1);
        pS_out[length-1] = '\n';
        pS_out[length] = '\0';
    }
    else{
        strncpy(pS_out, s, length);
        pS_out[length] = '\n';
        pS_out[length+1] = '\0';
    }
    return pS_out;
}
