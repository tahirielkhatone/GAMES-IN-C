#include <stdio.h>

// Predefined list of words
char *wordList[] = {"programming", "hangman", "computer", "game", "algorithm"};
#define WORD_COUNT 5

int getWordLength(char word[]) {
    int length = 0;
    while (word[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    int seed = 42; // Fixed seed for reproducibility
    char *word = wordList[seed % WORD_COUNT]; // Select a word based on the seed
    int length = getWordLength(word);
    char guess[length + 1];
    int attempts = 5; // Number of attempts

    printf("Welcome to the word guessing game!\n");
    printf("You have %d attempts to guess the word.\n", attempts);

    while (attempts > 0) {
        printf("Enter your guess: ");
        scanf("%s", guess);

        int correct = 1;
        for (int i = 0; i < length; i++) {
            if (guess[i] != word[i]) {
                correct = 0;
                break;
            }
        }

        if (correct) {
            printf("Congratulations! You guessed the word: %s\n", word);
            break;
        } else {
            attempts--;
            if (attempts > 0) {
                printf("Incorrect guess. Try again. You have %d attempts left.\n", attempts);
            }
        }
    }

    if (attempts == 0) {
        printf("You are out of attempts! The word was: %s\n", word);
    }

    return 0;
}
