#include <stdio.h>

// Function to insert an item into an array at a specified position
void insertItem(int arr[], int *size, int position, int item) {
    // Shift elements to the right to make space for the new item
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new item at the specified position
    arr[position] = item;
    // Increase the size of the array
    (*size)++;
}

int main() {
    // Define the array
    int arr[] = {64, 89, 75, 69, 85, 72, 102, 145, 164, 175};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Define the item to insert
    int ITEM = 123; // Replace 123 with your roll number or any desired value
    int position = 4; // Specify the position to insert the item

    // Insert the item into the array
    insertItem(arr, &size, position, ITEM);

    // Print the resulting array
    printf("Resultant array after inserting %d at position %d:\n", ITEM, position);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

