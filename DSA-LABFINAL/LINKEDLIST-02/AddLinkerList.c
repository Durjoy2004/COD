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

// Function to add two linked lists representing numbers
struct Node* addLists(struct Node *list1, struct Node *list2) {
    struct Node *result = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (list1 != NULL || list2 != NULL) {
        // Calculate sum of corresponding digits and carry
        sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);

        // Update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;

        // Update sum if it is greater than 10
        sum %= 10;

        // Create a new node with the calculated sum
        temp = createNode(sum);

        // If it is the first node, update the result
        if (result == NULL)
            result = temp;
        else
            prev->next = temp;

        // Move to the next nodes in the input lists
        prev = temp;
        if (list1)
            list1 = list1->next;
        if (list2)
            list2 = list2->next;
    }

    // If there is any carry left, add it to the result
    if (carry > 0)
        temp->next = createNode(carry);

    return result;
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
    // Create the first linked list
    struct Node *list1 = NULL;
    insertAtEnd(&list1, 8);
    insertAtEnd(&list1, 7);
    insertAtEnd(&list1, 9);
    insertAtEnd(&list1, 2);

    // Create the second linked list
    struct Node *list2 = NULL;
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 3);

    // Display the first linked list
    printf("List-1: ");
    displayList(list1);
    printf("\n");

    // Display the second linked list
    printf("List-2: ");
    displayList(list2);
    printf("\n");

    // Add the two linked lists
    struct Node *result = addLists(list1, list2);

    // Display the result
    printf("Adding said two lists: ");
    displayList(result);
    printf("\n");

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

    current = result;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

