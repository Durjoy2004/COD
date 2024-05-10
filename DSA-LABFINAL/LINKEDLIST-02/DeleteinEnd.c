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

// Function to delete the last node of the list
void deleteLastNode(struct Node **headRef) {
    if (*headRef == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If the list has only one node
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        printf("\nDeletion completed successfully.\n");
        return;
    }

    // Traverse to the second last node
    struct Node *current = *headRef;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the memory of the last node and update the next of the second last node to NULL
    free(current->next);
    current->next = NULL;
    printf("\nDeletion completed successfully.\n");
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("\nThe new list after deletion of the last node are:\n");
    while (current != NULL) {
        printf("Data = %d\n", current->data);
        current = current->next;
    }
}

int main() {
    int numNodes, data;
    printf("Input the number of nodes: ");
    scanf("%d", &numNodes);

    // Input data for each node and create the linked list
    struct Node *head = NULL;
    for (int i = 1; i <= numNodes; i++) {
        printf("Input data for node %d: ", i);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // Display the original linked list
    printf("\nData entered in the list are:\n");
    displayList(head);

    // Delete the last node of the list
    deleteLastNode(&head);

    // Display the modified linked list
    displayList(head);

    // Free the dynamically allocated memory
    struct Node *current = head;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
