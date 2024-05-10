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

// Function to delete a node from the middle of the list
void deleteMiddleNode(struct Node **headRef, int position) {
    if (*headRef == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *headRef;

    // If the node to be deleted is the first node
    if (position == 1) {
        *headRef = temp->next; // Change head
        free(temp); // Free the old head node
        printf("\nDeletion completed successfully.\n");
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    // Node temp->next is the node to be deleted
    struct Node *nextNode = temp->next->next;
    free(temp->next); // Free the memory
    temp->next = nextNode; // Unlink the deleted node
    printf("\nDeletion completed successfully.\n");
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("\nThe new list are:\n");
    while (current != NULL) {
        printf("Data = %d\n", current->data);
        current = current->next;
    }
}

int main() {
    int numNodes, data, position;
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

    // Input the position of the node to delete
    printf("\nInput the position of node to delete: ");
    scanf("%d", &position);

    // Delete the node from the middle of the list
    deleteMiddleNode(&head, position);

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
