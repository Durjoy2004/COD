#include <stdio.h>

// Function to perform bubble sort in ascending order
void bubbleSortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform bubble sort in descending order
void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Define the array
    int arr[] = {32, 51, 27, 85, 66, 23, 13, 57};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Sort the array in ascending order
    bubbleSortAscending(arr, size);
    printf("Array sorted in ascending order: ");
    printArray(arr, size);

    // Sort the array in descending order
    bubbleSortDescending(arr, size);
    printf("Array sorted in descending order: ");
    printArray(arr, size);

    return 0;
}

