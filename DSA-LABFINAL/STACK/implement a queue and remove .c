
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of the queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to insert an element into the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        exit(1);
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
}

// Function to remove an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    int removed = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return removed;
}

// Function to display the elements in the queue
void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->items[queue->rear]);
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    // Check if the queue is empty
    printf("Check the queue is empty or not? %s\n", isEmpty(&queue) ? "Yes" : "No");

    // Insert elements into the queue
    printf("\nInsert some elements into the queue:\n");
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    displayQueue(&queue);

    // Insert another element into the queue
    printf("\nInsert another element into the queue:\n");
    enqueue(&queue, 4);
    displayQueue(&queue);

    // Check if the queue is empty
    printf("\nCheck the queue is empty or not? %s\n", isEmpty(&queue) ? "Yes" : "No");

    return 0;
}
