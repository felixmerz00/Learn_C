#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char* generate_password(int length, int num_sign_class);
int calculate_Security(const char* password);
char get_random_letter(int letter_class);

int main()
{
    /*
    Password validation
    */
    char password[40];
    char* better_password;
    /* Security level has values from 1 - 3. 1 = weak, 2 = medium, 3 = strong*/
    int security_level;
    printf("Enter your password: \n");
    scanf("%s", password);
    printf("The entered password is: %s\n", password);

    /*security_level = calculate_Security(password);*/

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


    /*Recommend a better alternative for weak (-> medium alternative) and medium (-> strong alternative) passwords.
    Password generation*/
    /*better_password = generate_password(16, 4);
    printf("The better password is %s: ", better_password);*/
    printf("Better password: %s", generate_password(16, 4));

    return 0;
}

int calculate_Security(const char* password){
    int password_length;
    int security;

    /*Check the number of chars: <12 -> weak, 12-16 -> medium, >=16 -> strong*/
    password_length = strlen(password);
    if(password_length < 12){security = 1;}
    else if(password_length < 16){security = 2;}
    else{security = 3;}

    /*Check if the password contains lower-case chars, upper-case chars, numbers and symbols.
    If one or more types are missing the security level gets decreased by 1.*/
    int lowercase, uppercase, numbers, symbols, invalid_characters;
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
    if(lowercase == 1){printf("PW contains lower-case characters.\n");}
    if(uppercase == 1){printf("PW contains upper-case characters.\n");}
    if(numbers == 1){printf("PW contains numeric characters.\n");}
    if(symbols == 1){printf("PW contains symbols.\n");}
    if(invalid_characters == 1){printf("PW contains invalid characters.\n");}

    /*Edit strength variable based on contained characters.*/
    if(security > 1 && (lowercase == 0 || uppercase == 0 || numbers == 0 || symbols == 0)){
        security -= 1;
    }

    return security;
}

const char* generate_password(int length, int num_sign_class){
    char password[20] = "";
    srand(time(NULL));
    for(int i = 0; i < length; i++){
        char a = get_random_letter(rand()%4 + 1);
        /*char a = rand() % (122 + 1 - 97) + 97;*/
        strncat(password, &a, 1);
        printf("%s\n", password);
    }
    char *s = password;
    return s;
}

char get_random_letter(int letter_class){
    if (letter_class == 1){
        char a = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
        return a;
    }
        if (letter_class == 2){
        char a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
        return a;
    }
        if (letter_class == 3){
        char a = "0123456789"[rand() % 10];
        return a;
    }
        if (letter_class == 4){
        int array[] = {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126};
        char a = array[rand() % 32];
        return a;
    }

}
