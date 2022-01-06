#include <stdio.h>
#include <stdlib.h>

void draw_field(char positions[3][3]);
int check_for_win(char positions[3][3]);

int main()
{
    int gewinner_existiert = 0;
    char positions[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    draw_field(positions);
    gewinner_existiert = check_for_win(positions);

    int x_pos;
    int y_pos;
    char ch;
    while(gewinner_existiert == 0){
        /*Neuer input vom Spieler einlesen.*/
        printf("In welcher Zeile (1/2/3) möchtest du ein Zeichen setzen? ");
        scanf("%d", &x_pos);
        x_pos--;
        printf("In welcher Spalte (1/2/3) möchtest du ein Zeichen setzen? ");
        scanf("%d", &y_pos);
        y_pos--;
        printf("Welches Zeichen mchtest du setzen (x/o)? ");
        scanf(" %c", &ch);
        if(x_pos < 0 || x_pos > 2 || y_pos < 0 || y_pos > 2 || (ch != 'x' && ch != 'o')){
            printf("Ein eingegeben Wert is ungültig.\n");
            continue;
        }

        /*Input vom Spieler auf dem Spielfeld einzeichnen und überprüfen ob er gewonnen hat.*/
        positions[x_pos][y_pos] = ch;
        draw_field(positions);
        gewinner_existiert = check_for_win(positions);
    }

    return 0;
}

/*Spielfeld in Konsole malen*/
void draw_field(char positions[3][3])
{
    printf("\n%c|%c|%c\n", positions[0][0], positions[0][1], positions[0][2]);
    printf("-----\n");
    printf("%c|%c|%c\n", positions[1][0], positions[1][1], positions[1][2]);
    printf("-----\n");
    printf("%c|%c|%c\n\n", positions[2][0], positions[2][1], positions[2][2]);
}

/*Überprüfen ob ein spieler gewonnen hat. Returned 1 falls es einen Gewinner gibt, 0 falls es keinen Gewinner gibt.*/
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
                    return 1;
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
                    return 1;
                }
            }
        }
    }
    /*Diagonale 1 überprüfen*/
    if(positions[0][0] != ' ' && positions[0][0] == positions[1][1] && positions[0][0] == positions[2][2]){
        printf("%c wins the game!\n", positions[0][0]);
        return 1;
    }
    /*Diagonale 2 überprüfen*/
    if(positions[0][2] != ' ' && positions[0][2] == positions[1][1] && positions[0][2] == positions[2][0]){
        printf("%c wins the game!\n", positions[0][2]);
        return 1;
    }
    return 0;
}
