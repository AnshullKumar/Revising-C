// Simple Menu-Driven Stack Program
// • Implements a linear stack using an array (fixed size).
// • Provides basic operations: Push, Pop, Peek (view top), and Display.
// • Uses a menu loop so the user can repeatedly choose operations.
// • Handles stack overflow (when full) and underflow (when empty).

#include <stdio.h>

#define MAX 5   

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("\nStack Overflow!\n");  // The stack is full
    } else {
        stack[++top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow!\n");  // There are no elements in the stack
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

void peek() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nTop element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {    // will display from the top because popping elements will be popped in the same order it is displayed
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (View Top)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;  
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
