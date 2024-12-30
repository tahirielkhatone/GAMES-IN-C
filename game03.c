#include <stdio.h>

// Function to generate a pseudo-random number between 0 and 2
int generateRandomChoice() {
    static unsigned long next = 1;
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 3;
}

// Function to print the choice
void printChoice(int choice) {
    if (choice == 0)
        printf("Rock");
    else if (choice == 1)
        printf("Paper");
    else
        printf("Scissors");
}

int main() {
    int userChoice, computerChoice;

    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ");
    scanf("%d", &userChoice);

    computerChoice = generateRandomChoice();

    printf("You chose: ");
    printChoice(userChoice);
    printf("\nComputer chose: ");
    printChoice(computerChoice);
    printf("\n");

    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 0 && computerChoice == 2) ||
               (userChoice == 1 && computerChoice == 0) ||
               (userChoice == 2 && computerChoice == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}
