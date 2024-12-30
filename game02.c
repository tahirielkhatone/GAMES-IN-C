#include <stdio.h>

int generateRandomNumber() {
    // Using a simple linear congruential generator (LCG)
    static unsigned long next = 1;
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 100 + 1;
}

int main() {
    int number = generateRandomNumber();
    int guess, attempts = 0;

    printf("Welcome to the number guessing game!\n");
    printf("I have selected a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number);

    return 0;
}
