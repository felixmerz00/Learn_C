#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int secret_number = rand() % (10 + 1 - 0) + 0;
    int guess = 0;
    int guess_count = 0;
    printf("Secret number: %d\n", secret_number);
    while(guess != secret_number && guess_count < 3){
        printf("Guess the secret number: ");
        scanf("%d", &guess);
        guess_count += 1;
    }
    if(guess == secret_number){
        printf("You win!");
    }
    else{
        printf("You lose.");
    }

    return 0;
}
