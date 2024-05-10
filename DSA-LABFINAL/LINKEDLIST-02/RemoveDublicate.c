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

// Function to remove duplicates from a single unsorted linked list
void removeDuplicates(struct Node *head) {
    struct Node *current = head;

    // Check if the list is empty or has only one node
    if (current == NULL || current->next == NULL) {
        return;
    }

    // Traverse through the list
    while (current != NULL) {
        struct Node *runner = current;
        while (runner->next != NULL) {
            // If duplicate found, delete the duplicate node
            if (runner->next->data == current->data) {
                struct Node *temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Test data 1
    printf("Original Singly List:\n");
    struct Node *list1 = NULL;
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 4);
    displayList(list1);
    printf("After removing duplicate elements from the said singly list:\n");
    removeDuplicates(list1);
    displayList(list1);

    // Test data 2
    printf("\nOriginal Singly List:\n");
    struct Node *list2 = NULL;
    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 4);
    displayList(list2);
    printf("After removing duplicate elements from the said singly list:\n");
    removeDuplicates(list2);
    displayList(list2);

    // Free the dynamically allocated memory for each node
    struct Node *current = list1;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    current = list2;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

