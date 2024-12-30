#include <stdio.h>

// Function to initialize the display array
void initialize(char word[], char display[], int length) {
    for (int i = 0; i < length; i++) {
        display[i] = '_';
    }
    display[length] = '\0';
}

// Function to print the current state of the word
void displayWord(char display[]) {
    printf("Current word: ");
    for (int i = 0; display[i] != '\0'; i++) {
        printf("%c ", display[i]);
    }
    printf("\n");
}

// Function to check the user's guess
int checkGuess(char word[], char display[], char guess) {
    int found = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == guess) {
            display[i] = guess;
            found = 1;
        }
    }
    return found;
}

// Function to get the length of the word
int getWordLength(char word[]) {
    int length = 0;
    while (word[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char word[] = "programming"; // Secret word to guess
    int length = getWordLength(word);
    char display[length + 1];
    char guessedLetters[26] = {0}; // To track guessed letters
    int attempts = 6; // Number of wrong attempts allowed
    char guess;

    initialize(word, display, length);

    while (attempts > 0) {
        displayWord(display);
        printf("You have %d attempts left.\n", attempts);
        printf("Enter your guess: ");
        scanf(" %c", &guess);

        if (guessedLetters[guess - 'a']) {
            printf("You have already guessed that letter. Try again.\n");
            continue;
        }

        guessedLetters[guess - 'a'] = 1;

        if (!checkGuess(word, display, guess)) {
            attempts--;
            printf("Wrong guess!\n");
        }

        // Check if the word is completely guessed
        int complete = 1;
        for (int i = 0; i < length; i++) {
            if (display[i] == '_') {
                complete = 0;
                break;
            }
        }
        if (complete) {
            printf("Congratulations! You guessed the word: %s\n", word);
            break;
        }
    }

    if (attempts == 0) {
        printf("You are out of attempts! The word was: %s\n", word);
    }

    return 0;
}
