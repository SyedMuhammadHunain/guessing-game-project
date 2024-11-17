#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void title(){
    printf("-------------------------------------------------------\n");
    printf("                                                       \n");
    printf("          WELCOME TO THE NUMBER GUESSING GAME          \n");
    printf("                                                        \n");
    printf("          Created By:                                   \n");
    printf("                  Syed Muhammad Hunain                  \n\n");
    printf("--------------------------------------------------------\n\n");
    return;
}

void end_game() {
    printf("\n\n----------------------------------------------------\n");
    printf("          Thank You for Playing, See you next time!     \n");
    printf("--------------------------------------------------------\n\n");
    return;
}

int main() {
    int player_guess, computer_guess;
    int start, end;
    int player_attempts = 0;
    
    char* player_name = (char*) malloc(30 * sizeof(char));  

    title();

    printf("\nEnter your name here: ");
    scanf("%[^\n]s", player_name);

    printf("\nEnter your range: ");
    scanf("%d %d", &start, &end);
    
    /* */
    srand(time(0)); 
    computer_guess = rand() % (end - start + 1) + start;
    /*  */

    int i = 0;
    while (player_guess != computer_guess) {
        printf("\nGuess the number: ");
        scanf("%d", &player_guess);
        
        if (player_guess > end || player_guess < start) {
            printf("Invalid number! Guess a number between %d-%d", start, end);
            continue;;
        }

        player_attempts++;

        if (player_guess > computer_guess) {
            printf("\nYour guess is too high");
        } else if (player_guess < computer_guess) {
            printf("\nYour guess is too low");
        } else if (player_guess == computer_guess) {
            printf("----------------------------------------------\n");
            printf("Congratulations %s! You have guessed correctly\n", player_name);
            printf("----------------------------------------------\n\n");
            break;
        } 
        i++;
    }

    printf("\nPlayer Name: %s", player_name);
    printf("\nAttempts: %d", player_attempts);
    end_game();
    free(player_name);
    return 0;
}
