/* 
● Welcome to the Number Guessing Game!
● This is a simple number guessing game implemented in C.
● The player has to guess a randomly generated number within a certain range.
● The game provides feedback on whether the guess is too high, too low, or correct.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{   int random_number, number_to_guess;
    int number_of_guesses = 0;
    srand(time(NULL)); // Seed the random number generator

    printf("\nWelcome to the Number Guessing Game!\n");
    random_number = rand() % 101; // Generate a random number between 0 and 100

    do{
        printf("\nPlease enter your guess (between 0 and 100): ");
        scanf("%d", &number_to_guess);
        number_of_guesses++;
        
        if (number_to_guess < random_number) {
            printf("\nYour guess is too low. Guess a larger number.\n");
        }
        
        else if (number_to_guess > random_number) {
            printf("\nYour guess is too high. Guess a smaller number. \n");
        }
        
        else {
            printf("\nCongratulations! You have successfully guessed the number in %d attempts!\n", number_of_guesses);
        }
    } while (number_to_guess != random_number);

    printf("\nThank you for playing the game!\n");
}
