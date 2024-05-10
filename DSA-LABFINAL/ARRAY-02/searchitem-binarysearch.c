#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int item) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == item) {
            return mid; // Item found, return index
        } else if (arr[mid] < item) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Item not found
}

int main() {
    // Define the array (sorted)
    int arr[] = {11, 22, 30, 33, 40, 44, 55, 60, 66, 77, 80, 88, 99};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Define the item to search
    int ITEM = 22; // Specify the item to search for

    // Perform binary search
    int index = binarySearch(arr, size, ITEM);

    // Print the result
    if (index != -1) {
        printf("Item %d found at index %d.\n", ITEM, index);
    } else {
        printf("Item %d not found in the array.\n", ITEM);
    }

    return 0;
}

