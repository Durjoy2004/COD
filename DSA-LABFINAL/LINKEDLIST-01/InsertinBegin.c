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

// Function to insert a new node at the beginning of the list
struct Node* insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = newNode;
    } else {
        // Make the new node point to the current head
        newNode->next = head;
        // Update the head to point to the new node
        head = newNode;
    }
    return head;
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("Data entered in the list are:\n");
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
        head = insertAtBeginning(head, data);
    }

    // Display the original linked list
    displayList(head);

    // Input data to insert at the beginning of the list
    int newData;
    printf("\nInput data to insert at the beginning of the list: ");
    scanf("%d", &newData);

    // Insert the new data at the beginning of the list
    head = insertAtBeginning(head, newData);

    // Display the modified linked list
    printf("\nData after inserted in the list are:\n");
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

