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

// Function to merge two sorted linked lists
struct Node* merge(struct Node *list1, struct Node *list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node *mergedList = NULL;
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = merge(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = merge(list1, list2->next);
    }
    return mergedList;
}

// Function to split the linked list into two halves
void split(struct Node *head, struct Node **front, struct Node **back) {
    struct Node *fast = head->next;
    struct Node *slow = head;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

// Function to perform merge sort on the linked list
void mergeSort(struct Node **headRef) {
    struct Node *head = *headRef;
    struct Node *front;
    struct Node *back;

    if (head == NULL || head->next == NULL) {
        return;
    }

    split(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = merge(front, back);
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
    // Create the singly linked list
    struct Node *head = NULL;
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 5);

    // Display the original list
    printf("Original list: ");
    displayList(head);
    printf("\n");

    // Sort the list using merge sort
    mergeSort(&head);

    // Display the sorted list
    printf("After sorting the list: ");
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

