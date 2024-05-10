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

// Function to merge two sorted linked lists into a single sorted linked list
struct Node* mergeSortedLists(struct Node *list1, struct Node *list2) {
    struct Node *mergedList = NULL;
    struct Node *tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            if (mergedList == NULL) {
                mergedList = tail = list1;
            } else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = tail = list2;
            } else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }

    // Append the remaining nodes of list1 or list2 (if any)
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return mergedList;
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
    // Create the first sorted linked list
    struct Node *list1 = NULL;
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);
    insertAtEnd(&list1, 7);

    // Create the second sorted linked list
    struct Node *list2 = NULL;
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    // Display the first sorted linked list
    printf("First sorted linked list: ");
    displayList(list1);
    printf("\n");

    // Display the second sorted linked list
    printf("Second sorted linked list: ");
    displayList(list2);
    printf("\n");

    // Merge the two sorted linked lists
    struct Node *mergedList = mergeSortedLists(list1, list2);

    // Display the merged sorted linked list
    printf("After merging the two sorted lists: ");
    displayList(mergedList);
    printf("\n");

    // Free the dynamically allocated memory for each node
    struct Node *current = mergedList;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

