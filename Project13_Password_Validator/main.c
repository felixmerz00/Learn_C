#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Password validation
    */
    char password[40];
    /* Security level has values from 1 - 3. 1 = weak, 2 = medium, 3 = strong*/
    int security_level;
    int password_length;
    printf("Enter your password: \n");
    scanf("%s", password);
    printf("The entered password is: %s\n", password);


/*ö muss als ungültig gekennzeichnet werden*/

    /*
    Check the number of chars: <12 -> weak, 12-16 -> medium, >=16 -> strong
    */
    password_length = strlen(password);
    if(password_length < 12){
        security_level = 1;

    }
    else if(password_length < 16){
        security_level = 2;
    }
    else{
        security_level = 3;
    }

    int letter = 'a';

    /*
    Check if the password contains lower-case chars, upper-case chars, numbers and symbols.
    If one or more types are missing the security level gets decreased by 1.
    */
    int lowercase = 0;
    int uppercase = 0;
    int numbers = 0;
    int symbols = 0;
    int invalid_characters = 0;

    for(int i = 0; i < password_length; i++){
        if(97 <= password[i] && password[i] <= 122){
            lowercase = 1;
        }
        else if(65 <= password[i] && password[i] <= 90){
            uppercase = 1;
        }
        else if(48 <= password[i] && password[i] <= 57){
            numbers = 1;
        }
        else if((33 <= password[i] && password[i] <= 47) ||
                (58 <= password[i] && password[i] <= 64) ||
                (91 <= password[i] && password[i] <= 96) ||
                (123 <= password[i] && password[i] <= 126)){
            symbols = 1;
            }
        else{
            invalid_characters = 1;
        }
    }
    if(lowercase == 1){
        printf("PW contains lower-case characters.\n");
    }
    if(uppercase == 1){
        printf("PW contains upper-case characters.\n");
    }
    if(numbers == 1){
        printf("PW contains numeric characters.\n");
    }
    if(symbols == 1){
        printf("PW contains symbols.\n");
    }
    if(invalid_characters == 1){
        printf("PW contains invalid characters.\n");
    }

    /*Edit strength variable based on contained characters.*/
    if(security_level > 1 && (lowercase == 0 || uppercase == 0 || numbers == 0 || symbols == 0)){
        security_level -= 1;
    }

    /*Print security level.*/
    if(security_level == 1){
        printf("The entered password is weak.\n");
    }
    else if(security_level == 2){
        printf("The entered password has medium strength.\n");
    }
    else if(security_level == 3){
        printf("The entered password is strong.\n");
    }


    /*
    Recommend a better alternative for weak (-> medium alternative) and medium (-> strong alternative) passwords.
    Password generation
    */

    return 0;
}
