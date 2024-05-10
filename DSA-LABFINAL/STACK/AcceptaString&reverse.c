#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the structure of the stack
struct Stack {
    char items[MAX_SIZE];
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

// Function to push a character onto the stack
void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

// Function to pop a character from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char *str) {
    // Create a stack
    struct Stack stack;
    initializeStack(&stack);

    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    // Pop each character from the stack and store it back in the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX_SIZE];

    // Input a string
    printf("Input a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from input string
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str);

    // Display the reversed string
    printf("Reversed string using a stack is: %s\n", str);

    return 0;
}

