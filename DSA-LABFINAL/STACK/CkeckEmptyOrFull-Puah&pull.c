#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

// Define the structure of the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to display the elements in the stack
void displayStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Original Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack1, stack2;
    initializeStack(&stack1);
    initializeStack(&stack2);

    // Push elements onto stack1
    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);

    // Display stack1 and check if it is full
    printf("Stack size: %d\n", MAX_SIZE);
    displayStack(&stack1);
    push(&stack1, 4); // Attempt to push another value
    printf("Push another value and check if the stack is full or not!\n");

    // Check if stack1 is full
    if (isFull(&stack1)) {
        printf("Stack is full!\n");
    } else {
        printf("Stack is not full!\n");
    }
    printf("\n");

    // Push elements onto stack2
    push(&stack2, 10);
    push(&stack2, 20);

    // Display stack2 and check if it is full
    printf("Stack size: %d\n", MAX_SIZE);
    displayStack(&stack2);
    printf("Check the said stack is full or not!\n");

    // Check if stack2 is full
    if (isFull(&stack2)) {
        printf("Stack is full!\n");
    } else {
        printf("Stack is not full!\n");
    }

    return 0;
}

