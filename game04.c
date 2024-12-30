#include <stdio.h>

// Function to generate a pseudo-random number between 0 and 2
int generateRandomChoice() {
    static unsigned long next = 1;
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 3;
}

// Function to get user choice as an integer
int getUserChoice() {
    char input[10];
    int choice = -1;

    printf("Enter your choice (rock, paper, scissors): ");
    scanf("%s", input);

    if (input[0] == 'r' && input[1] == 'o' && input[2] == 'c' && input[3] == 'k' && input[4] == '\0') {
        choice = 0;
    } else if (input[0] == 'p' && input[1] == 'a' && input[2] == 'p' && input[3] == 'e' && input[4] == 'r' && input[5] == '\0') {
        choice = 1;
    } else if (input[0] == 's' && input[1] == 'c' && input[2] == 'i' && input[3] == 's' && input[4] == 's' && input[5] == 'o' && input[6] == 'r' && input[7] == 's' && input[8] == '\0') {
        choice = 2;
    } else {
        printf("Invalid choice. Try again.\n");
    }

    return choice;
}

// Function to print the choice
void printChoice(int choice) {
    if (choice == 0)
        printf("Rock");
    else if (choice == 1)
        printf("Paper");
    else if (choice == 2)
        printf("Scissors");
}

int main() {
    int userChoice, computerChoice;
    char playAgain;

    do {
        userChoice = -1;
        while (userChoice == -1) {
            userChoice = getUserChoice();
        }

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

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}