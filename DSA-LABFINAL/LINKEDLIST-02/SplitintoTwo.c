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

// Function to split the linked list into two halves
void splitList(struct Node *head, struct Node **firstHalfRef, struct Node **secondHalfRef) {
    if (head == NULL) {
        *firstHalfRef = NULL;
        *secondHalfRef = NULL;
        return;
    }

    struct Node *slowPtr = head;
    struct Node *fastPtr = head->next;

    // Move the fast pointer two steps and the slow pointer one step at a time
    while (fastPtr != NULL) {
        fastPtr = fastPtr->next;
        if (fastPtr != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }

    // Split the list into two halves at the slow pointer position
    *firstHalfRef = head;
    *secondHalfRef = slowPtr->next;
    slowPtr->next = NULL;
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
    // Test data 1
    printf("Original List: ");
    struct Node *list1 = NULL;
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 4);
    insertAtEnd(&list1, 5);
    displayList(list1);
    printf("\n");

    struct Node *firstHalf1 = NULL;
    struct Node *secondHalf1 = NULL;
    splitList(list1, &firstHalf1, &secondHalf1);

    printf("Split the said singly linked list into halves:\n");
    printf("First half: ");
    displayList(firstHalf1);
    printf("\nSecond half: ");
    displayList(secondHalf1);
    printf("\n");

    // Free the dynamically allocated memory for each node
    struct Node *current = list1;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    // Test data 2
    printf("\nOriginal List: ");
    struct Node *list2 = NULL;
    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 5);
    insertAtEnd(&list2, 6);
    displayList(list2);
    printf("\n");

    struct Node *firstHalf2 = NULL;
    struct Node *secondHalf2 = NULL;
    splitList(list2, &firstHalf2, &secondHalf2);

    printf("Split the said singly linked list into halves:\n");
    printf("First half: ");
    displayList(firstHalf2);
    printf("\nSecond half: ");
    displayList(secondHalf2);
    printf("\n");

    // Free the dynamically allocated memory for each node
    current = list2;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
