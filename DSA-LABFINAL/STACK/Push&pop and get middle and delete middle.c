#include <stdio.h>
#include <stdlib.h>

// Define the structure of a stack node
struct Node {
    int data;
    struct Node *next;
};

// Define the structure of the stack
struct Stack {
    struct Node *top;
    struct Node *middle;
    int count; // Number of elements in the stack
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = NULL;
    stack->middle = NULL;
    stack->count = 0;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;

    if (stack->count == 1) {
        stack->middle = newNode;
    } else if (stack->count % 2 != 0) {
        stack->middle = stack->middle->next;
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node *temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->count--;

    if (stack->count % 2 == 0) {
        stack->middle = stack->middle->next;
    }

    return popped;
}

// Function to get the middle element of the stack
int getMiddle(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->middle->data;
}

// Function to delete the middle element of the stack
void deleteMiddle(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    struct Node *temp = stack->middle;
    stack->middle = stack->middle->next;
    free(temp);
    stack->count--;

    if (stack->count % 2 == 0) {
        stack->middle = stack->middle->next;
    }
}

// Function to display the elements in the stack
void displayStack(struct Stack *stack) {
    struct Node *current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 88);
    push(&stack, 15);
    push(&stack, 26);
    push(&stack, 32);
    push(&stack, 23);

    // Display current stack elements and middle element
    displayStack(&stack);
    printf("Middle element: %d\n", getMiddle(&stack));

    // Delete middle element of the stack and display the stack and middle element
    deleteMiddle(&stack);
    displayStack(&stack);
    printf("Middle element: %d\n", getMiddle(&stack));

    // Delete middle element of the stack again and display the stack and middle element
    deleteMiddle(&stack);
    displayStack(&stack);
    printf("Middle element: %d\n", getMiddle(&stack));

    return 0;
}

