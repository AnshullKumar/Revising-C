// Simple Menu-Driven Doubly Linked List Program
// ---------------------------------------------
// • Implements a doubly linked list using dynamic memory allocation.
// • Provides basic operations:
//  - Insert (at beginning, end, at any position),
//  - Delete (by value),
//  - Display (forward and reverse).
// • Uses a menu loop so the user can repeatedly choose operations.
// • Handles empty list cases and memory management.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("%d inserted at beginning.\n", data);
}
