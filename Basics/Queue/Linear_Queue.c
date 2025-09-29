// Simple Menu-Driven Linear Queue Program
// • Implements a linear queue using an array (fixed size).
// • Provides basic operations: Enqueue, Dequeue, Peek (view front), and Display.
// • Uses a menu loop so the user can repeatedly choose operations.
// • Handles queue overflow (when full) and underflow (when empty).


#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow!\n");  // The queue is full
    } else {
        if (front == -1) front = 0;    // First element being added
        queue[++rear] = value;
        printf("%d enqueued into queue.\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow!\n");  // There are no elements in the queue
        front = rear = -1;              // Reset queue when empty
    } else {
        printf("%d dequeued from queue.\n", queue[front++]);
    }
}