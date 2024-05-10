#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of the two stacks
struct TwoStacks {
    int items[MAX_SIZE];
    int top1; // Top index of stack 1
    int top2; // Top index of stack 2
};

// Function to initialize the two stacks
void initializeStacks(struct TwoStacks *stacks) {
    stacks->top1 = -1; // Initialize top of stack 1
    stacks->top2 = MAX_SIZE; // Initialize top of stack 2
}

// Function to check if stack 1 is full
int isFull1(struct TwoStacks *stacks) {
    return stacks->top1 + 1 == stacks->top2;
}

// Function to check if stack 2 is full
int isFull2(struct TwoStacks *stacks) {
    return stacks->top2 - 1 == stacks->top1;
}

// Function to check if stack 1 is empty
int isEmpty1(struct TwoStacks *stacks) {
    return stacks->top1 == -1;
}

// Function to check if stack 2 is empty
int isEmpty2(struct TwoStacks *stacks) {
    return stacks->top2 == MAX_SIZE;
}

// Function to push an element onto stack 1
void push1(struct TwoStacks *stacks, int value) {
    if (isFull1(stacks)) {
        printf("Stack 1 Overflow\n");
        exit(1);
    }
    stacks->items[++stacks->top1] = value;
}

// Function to push an element onto stack 2
void push2(struct TwoStacks *stacks, int value) {
    if (isFull2(stacks)) {
        printf("Stack 2 Overflow\n");
        exit(1);
    }
    stacks->items[--stacks->top2] = value;
}

// Function to pop an element from stack 1
int pop1(struct TwoStacks *stacks) {
    if (isEmpty1(stacks)) {
        printf("Stack 1 Underflow\n");
        exit(1);
    }
    return stacks->items[stacks->top1--];
}

// Function to pop an element from stack 2
int pop2(struct TwoStacks *stacks) {
    if (isEmpty2(stacks)) {
        printf("Stack 2 Underflow\n");
        exit(1);
    }
    return stacks->items[stacks->top2++];
}

int main() {
    struct TwoStacks stacks;
    initializeStacks(&stacks);

    // Push elements onto stack 1
    push1(&stacks, 1);
    push1(&stacks, 2);
    push1(&stacks, 3);

    // Pop elements from stack 1
    printf("%d popped from stack 1\n", pop1(&stacks));
    printf("%d popped from stack 1\n", pop1(&stacks));
    printf("%d popped from stack 1\n\n", pop1(&stacks));

    // Push elements onto stack 2
    push2(&stacks, 10);
    push2(&stacks, 20);
    push2(&stacks, 30);

    // Pop elements from stack 2
    printf("%d popped from stack 2\n", pop2(&stacks));
    printf("%d popped from stack 2\n", pop2(&stacks));
    printf("%d popped from stack 2\n", pop2(&stacks));

    return 0;
}

