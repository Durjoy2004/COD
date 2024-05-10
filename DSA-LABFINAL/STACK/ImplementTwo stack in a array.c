

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to get the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// Function to sort a stack in ascending order using another stack
void sortStack(struct Stack *inputStack, struct Stack *tempStack) {
    while (!isEmpty(inputStack)) {
        int temp = pop(inputStack);
        while (!isEmpty(tempStack) && peek(tempStack) > temp) {
            push(inputStack, pop(tempStack));
        }
        push(tempStack, temp);
    }
    while (!isEmpty(tempStack)) {
        push(inputStack, pop(tempStack));
    }
}

// Function to display the elements in the stack
void displayStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack inputStack, tempStack;
    initializeStack(&inputStack);
    initializeStack(&tempStack);

    // Push elements onto the stack
    push(&inputStack, 1);
    push(&inputStack, 5);
    push(&inputStack, 5);
    push(&inputStack, 2);
    push(&inputStack, 3);
    push(&inputStack, 8);

    // Display original stack
    printf("Original stack: ");
    displayStack(&inputStack);

    // Sort the stack
    sortStack(&inputStack, &tempStack);

    // Display sorted stack
    printf("Sorted stack: ");
    displayStack(&inputStack);

    return 0;
}
