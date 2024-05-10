#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
    int max; // Variable to store the maximum element
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
    stack->max = -__INT_MAX__; // Initialize max to minimum integer value
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
    // Update max if the pushed value is larger
    if (value > stack->max) {
        stack->max = value;
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
    // Update max if the popped value is the maximum
    if (popped == stack->max) {
        // Find the new maximum in the remaining stack
        stack->max = -__INT_MAX__;
        for (int i = 0; i <= stack->top; i++) {
            if (stack->items[i] > stack->max) {
                stack->max = stack->items[i];
            }
        }
    }
    return popped;
}

// Function to display the maximum element in the stack
void displayMax(struct Stack *stack) {
    printf("Maximum element: %d\n", stack->max);
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
    push(&stack, 5);
    push(&stack, 2);
    push(&stack, 1);
    push(&stack, 6);
    push(&stack, 8);

    // Display current stack elements and maximum element
    displayStack(&stack);
    displayMax(&stack);

    // Remove two elements
    printf("\nAfter removing two elements:\n");
    pop(&stack);
    pop(&stack);
    displayStack(&stack);
    displayMax(&stack);

    // Add one element
    printf("\nAfter adding one element:\n");
    push(&stack, 10);
    displayStack(&stack);
    displayMax(&stack);

    return 0;
}

