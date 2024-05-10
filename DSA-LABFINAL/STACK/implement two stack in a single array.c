#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
    int min; // Variable to store the minimum element
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
    stack->min = __INT_MAX__; // Initialize min to maximum integer value
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
        printf("Stack Overflow\n");
        exit(1);
    }
    // Update min if the pushed value is smaller
    if (value < stack->min) {
        stack->min = value;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int popped = stack->items[stack->top--];
    // Update min if the popped value is the minimum
    if (popped == stack->min) {
        // Find the new minimum in the remaining stack
        stack->min = __INT_MAX__;
        for (int i = 0; i <= stack->top; i++) {
            if (stack->items[i] < stack->min) {
                stack->min = stack->items[i];
            }
        }
    }
    return popped;
}

// Function to display the minimum element in the stack
void displayMin(struct Stack *stack) {
    printf("Minimum element: %d\n", stack->min);
}

// Function to display the elements in the stack
void displayStack(struct Stack *stack) {
    printf("Current stack elements:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 9);
    push(&stack, 2);
    push(&stack, 4);
    push(&stack, 2);
    push(&stack, 4);

    // Display current stack elements and minimum element
    displayStack(&stack);
    displayMin(&stack);

    // Remove two elements
    printf("\nAfter removing two elements:\n");
    pop(&stack);
    pop(&stack);
    displayStack(&stack);
    displayMin(&stack);

    // Add one element
    printf("\nAfter adding one element:\n");
    push(&stack, 1);
    displayStack(&stack);
    displayMin(&stack);

    return 0;
}

