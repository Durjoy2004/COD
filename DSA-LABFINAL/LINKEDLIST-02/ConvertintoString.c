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

// Function to convert a singly linked list into a string
char* convertToString(struct Node *head) {
    char *result = (char*)malloc(100 * sizeof(char)); // Assuming a maximum length of 100 characters
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    struct Node *current = head;
    int index = 0;
    while (current != NULL) {
        // Convert the data of each node to string and concatenate it to the result string
        int len = snprintf(NULL, 0, "%d", current->data);
        char *temp = (char*)malloc((len + 1) * sizeof(char));
        snprintf(temp, len + 1, "%d", current->data);
        for (int i = 0; temp[i] != '\0'; i++) {
            result[index++] = temp[i];
        }
        free(temp); // Free the memory allocated for temp
        current = current->next;
        if (current != NULL) {
            result[index++] = ' '; // Add space between elements
        }
    }
    result[index] = '\0'; // Add null terminator at the end
    return result;
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("\nThe linked list: %s\n", convertToString(head));
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

    // Display the linked list as a string
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
