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

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("%d inserted at end.\n", data);
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted at end.\n", data);
}

void insertAtPosition(int data, int pos) {
    if (head == NULL && pos != 1) {
    printf("Invalid position!\n");
    return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
 
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("%d inserted at position %d.\n", data, pos);
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}

void delete_End(){
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if(head->next == NULL){
        printf("%d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head; 
    while (temp->next != NULL) {
        temp = temp->next;
    }
       
    printf("%d deleted from end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

void delete_Position(int pos){
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    struct Node *temp = head;
    
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    printf("%d deleted from position %d.\n", temp->data, pos);
    free(temp);
}