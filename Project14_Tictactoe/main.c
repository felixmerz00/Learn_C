#include <stdio.h>
#include <stdlib.h>

void draw_field(char positions[3][3]);

int main()
{
    char positions[3][3] = {{'o', 'o', 'x'}, {'x', 'o', 'o'}, {'x', 'x', 'o'}};
    draw_field(positions);
    check_for_win(positions);
    return 0;
}

void draw_field(char positions[3][3])
{
    printf("\n%c|%c|%c\n", positions[0][0], positions[0][1], positions[0][2]);
    printf("-----\n");
    printf("%c|%c|%c\n", positions[1][0], positions[1][1], positions[1][2]);
    printf("-----\n");
    printf("%c|%c|%c\n\n", positions[2][0], positions[2][1], positions[2][2]);
}

int check_for_win(char positions[3][3])
{
    /*Zeilen überprüfen*/
    for(int zeile = 0; zeile < 3; zeile++){
        char current_char = positions[zeile][0];
        int score = 1;
        if(current_char == 'x' || current_char == 'o'){
            for(int spalte = 1; spalte < 3; spalte++){
                if(current_char == positions[zeile][spalte]){
                    score++;
                }
                if(score == 3){
                    printf("%c wins the game!\n", current_char);
                }
            }
        }
    }

    /*Spalten überprüfen*/
    for(int spalte = 0; spalte < 3; spalte++){
        char current_char = positions[0][spalte];
        int score = 1;
        if(current_char == 'x' || current_char == 'o'){
            for(int zeile = 1; zeile < 3; zeile++){
                if(current_char == positions[zeile][spalte]){
                    score++;
                }
                if(score == 3){
                    printf("%c wins the game!\n", current_char);
                }
            }
        }
    }
    /*Diagonale 1 überprüfen*/
    if(positions[0][0] == positions[1][1] && positions[0][0] == positions[2][2]){
        printf("%c wins the game!\n", positions[0][0]);
    }
    /*Diagonale 2 überprüfen*/
    if(positions[0][2] == positions[1][1] && positions[0][2] == positions[2][0]){
        printf("%c wins the game!\n", positions[0][2]);
    }

}
