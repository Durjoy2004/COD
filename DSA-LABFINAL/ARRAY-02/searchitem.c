#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int item) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            return i; // Return the index of the item if found
        }
    }
    return -1; // Return -1 if the item is not found
}

int main() {
    // Define the array
    int arr[] = {11, 22, 30, 33, 40, 44, 55, 60, 66, 77, 80, 88, 99};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Define the item to search
    int ITEM = 99; // Specify the item to search for

    // Perform linear search
    int index = linearSearch(arr, size, ITEM);

    // Print the result
    if (index != -1) {
        printf("Item %d found at index %d.\n", ITEM, index);
    } else {
        printf("Item %d not found in the array.\n", ITEM);
    }

    return 0;
}

