#include <stdio.h>

#define SIZE 10

void generateRandomNumbers(int arr[], int size, int seed) {
    int next = seed;
    for (int i = 0; i < size; i++) {
        next = next * 1103515245 + 12345;
        arr[i] = (next / 65536) % 100; // Generate numbers between 0 and 99
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int compareArrays(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are not the same
        }
    }
    return 1; // Arrays are the same
}

int main() {
    int arr[SIZE], userArr[SIZE], sortedArr[SIZE];
    int seed = 42; // Fixed seed for reproducibility

    // Generate random numbers and print them
    generateRandomNumbers(arr, SIZE, seed);
    printf("Unsorted array: ");
    printArray(arr, SIZE);

    // Copy the original array to the sorted array
    for (int i = 0; i < SIZE; i++) {
        sortedArr[i] = arr[i];
    }

    // Sort the array
    bubbleSort(sortedArr, SIZE);

    // Prompt the user to input their sorted array
    printf("Enter the sorted array (space-separated): ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &userArr[i]);
    }

    // Compare user's sorted array with the correct sorted array
    if (compareArrays(userArr, sortedArr, SIZE)) {
        printf("Congratulations! You sorted the array correctly.\n");
    } else {
        printf("Sorry, the sorted array is incorrect. The correct sorted array is: ");
        printArray(sortedArr, SIZE);
    }

    return 0;
}
