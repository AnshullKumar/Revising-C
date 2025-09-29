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
        printf("\nQueue Overflow!\n");  
    } else {
        if (front == -1) front = 0;    // Cold start
        queue[++rear] = value;
        printf("%d enqueued into queue.\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow!\n");  
        front = rear = -1;              // Resets the queue when empty
    } else {
        printf("%d dequeued from queue.\n", queue[front++]);
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nFront element is: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements (front to rear):\n");
        for (int i = front; i <= rear; i++) {  // Display from front to rear
            printf("%d\n", queue[i]);
        }
    }
}