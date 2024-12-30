#include <stdio.h>

int main() {
    int number, guess, tries = 0;
    // Seed the random number generator manually
    int seed = 42; // Using a fixed seed value
    number = seed % 100 + 1; // Generate a number between 1 and 100

    printf("Welcome to the number guessing game!\n");
    printf("I have selected a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > number) {
            printf("Too high!\n");
        } else if (guess < number) {
            printf("Too low!\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }
    } while (guess != number);

    return 0;
}
