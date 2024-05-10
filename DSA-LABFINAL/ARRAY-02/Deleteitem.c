#include <stdio.h>

// Function to delete an item from an array
void deleteItem(int arr[], int *size, int item) {
    int found = 0; // Flag to indicate if the item is found
    for (int i = 0; i < *size; i++) {
        if (arr[i] == item) {
            found = 1; // Set the flag to indicate that the item is found
            // Shift elements to the left to overwrite the item to be deleted
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--; // Decrease the size of the array
            break; // Exit the loop after deleting the first occurrence of the item
        }
    }
    if (!found) {
        printf("Item %d not found in the array.\n", item);
    }
}

int main() {
    // Define the array
    int arr[] = {64, 89, 75, 69, 85, 72, 102, 145, 164, 175};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Define the item to delete
    int ITEM = 89; // Specify the item to delete

    // Delete the item from the array
    deleteItem(arr, &size, ITEM);

    // Print the resulting array
    printf("Resultant array after deleting %d:\n", ITEM);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
