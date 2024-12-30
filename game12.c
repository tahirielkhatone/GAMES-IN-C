#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int arr[], int size) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1; // Assume the array is sorted

        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                sorted = 0; // Array is not sorted
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Welcome to the number sorting game!\n");
    printf("Here is the unsorted array:\n");
    printArray(arr, size);

    printf("Sort the array in ascending order.\n");
    sortArray(arr, size);

    printf("Here is the sorted array:\n");
    printArray(arr, size);

    printf("Congratulations! You have sorted the array correctly.\n");

    return 0;
}
