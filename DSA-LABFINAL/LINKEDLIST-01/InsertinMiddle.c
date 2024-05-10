
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

// Function to insert a new node in the middle of the list
void insertInMiddle(struct Node **headRef, int data, int position) {
    struct Node *newNode = createNode(data);
    if (*headRef == NULL) {
        // If the list is empty, the new node becomes the head
        *headRef = newNode;
    } else {
        // Traverse to the node before the specified position
        struct Node *current = *headRef;
        for (int i = 1; i < position - 1 && current->next != NULL; i++) {
            current = current->next;
        }
        // Insert the new node after the current node
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("The new list are:\n");
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
        insertInMiddle(&head, data, i);
    }

    // Display the original linked list
    printf("Data entered in the list are:\n");
    displayList(head);

    // Input data to insert in the middle of the list
    printf("\nInput data to insert in the middle of the list: ");
    scanf("%d", &data);
    printf("Input the position to insert new node: ");
    scanf("%d", &position);

    // Insert the new data in the middle of the list
    insertInMiddle(&head, data, position);

    // Display the modified linked list
    printf("\nInsertion completed successfully.\n");
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
