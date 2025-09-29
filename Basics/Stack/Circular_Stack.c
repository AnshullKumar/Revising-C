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
