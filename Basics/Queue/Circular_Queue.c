// Simple Menu-Driven Circular Queue Program
// • Implements a circular queue using an array (fixed size).
// • Provides basic operations: Enqueue, Dequeue, Front (view first), and Display.
// • Uses a menu loop so the user can repeatedly choose operations.
// • Handles queue overflow (when full) and underflow (when empty).

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);                 
}

void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue Overflow!\n");   
    } else {
        if (isEmpty()) {
            front = 0;                   // Cold Start
        }
        rear = (rear + 1) % MAX;         // Warp rear pointer in circular manner
        queue[rear] = value;
        printf("%d enqueued into queue.\n", value);
    }
}

