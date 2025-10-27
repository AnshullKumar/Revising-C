// Simple Menu-Driven Circular Linked List Program
// -----------------------------------------------
// • Implements a Circular Singly Linked List using dynamic memory allocation.
// • Provides basic operations:
//    - Insert (at beginning, end, at any position),
//    - Delete (at beginning, end, at any position),
//    - Count total nodes,
//    - Display all elements in circular order.
// • Uses a menu loop so the user can repeatedly choose operations.
// • Automatically connects the last node back to the head to maintain circularity.
// • Handles empty list and invalid position cases safely.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;

};

struct Node *head = NULL;  

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void insertAtPosition(int data, int pos) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    if (pos == 1) {
        insertAtBeginning(data);
        free(newNode);
        return;
    }
    struct Node *temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp->next == head && pos > 2) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    head = head->next;
    last->next = head;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    struct Node *del = temp->next;
    temp->next = head;
    free(del);
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp->next == head) {
        printf("Position out of range!\n");
        return;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void countNodes() {
    if (head == NULL) {
        printf("Number of elements: 0\n");
        return;
    }
    int count = 0;
    struct Node *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("Number of elements: %d\n", count);
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("List elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Count Elements\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                countNodes();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
