//Simple Menu Driven Circular-Stack
// • Uses formula: top = (top + 1) % MAX so index wraps around.
// • Push wraps to the beginning if end is reached.
// • Pop decreases top, and when stack becomes empty, resets top = -1.
// • Provides Push, Pop, Peek, Display, and Exit in a menu-driven program.


#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push %d\n", value);
    } else {
        top = (top + 1) % MAX;  // wrap using modulo
        stack[top] = value;
        printf("%d pushed into circular stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Nothing to pop.\n");
    } else {
        printf("%d popped from circular stack.\n", stack[top]);
        top--;  
        if (top < 0) {  // reset if the stack empty
            top = -1;
        }
    }
}

void peek() {
    if (top == -1) {
        printf("\nCircular Stack is empty.\n");
    } else {
        printf("\nTop element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("\nCircular Stack is empty.\n");
    } else {
        printf("\nCircular Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Stack Menu ---\n");
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
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}