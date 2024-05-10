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

// Function to delete the first node of the list
struct Node* deleteFirstNode(struct Node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
    } else {
        struct Node *temp = head;
        head = head->next;
        printf("\nData of node 1 which is being deleted is: %d\n", temp->data);
        free(temp);
    }
    return head;
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("\nData, after deletion of first node:\n");
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
        struct Node *newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    // Display the original linked list
    printf("\nData entered in the list are:\n");
    displayList(head);

    // Delete the first node of the list
    head = deleteFirstNode(head);

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

