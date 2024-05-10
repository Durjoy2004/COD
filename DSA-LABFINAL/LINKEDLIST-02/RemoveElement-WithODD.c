#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **headRef, int data) {
    struct Node *newNode = createNode(data);
    if (*headRef == NULL) {
        // If the list is empty, the new node becomes the head
        *headRef = newNode;
    } else {
        // Traverse to the last node
        struct Node *current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        // Insert the new node after the last node
        current->next = newNode;
    }
}

// Function to remove elements with odd indices from a singly linked list
void removeOddIndices(struct Node **headRef) {
    struct Node *current = *headRef;
    struct Node *prev = NULL;
    int index = 1;

    while (current != NULL) {
        if (index % 2 != 0) {
            // If the index is odd, remove the current node
            struct Node *temp = current;
            if (prev == NULL) {
                *headRef = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
        index++;
    }
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    // Create the original linked list
    struct Node *head = NULL;
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);

    // Display the original linked list
    printf("Original linked list: ");
    displayList(head);
    printf("\n");

    // Remove elements with odd indices
    removeOddIndices(&head);

    // Display the modified linked list
    printf("Linked list after removing odd indices: ");
    displayList(head);
    printf("\n");

    // Free the dynamically allocated memory for each node
    struct Node *current = head;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

