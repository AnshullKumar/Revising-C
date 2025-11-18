// Hash Collision — Linear Chaining (Linked Lists)
// -----------------------------------------------
// Demonstrates collision resolution using linked lists.
// Hash function: index = value % SIZE (SIZE = 10).
// Values {12, 22, 32, 42, 52} all hash to index 2, forming a chain.
// New nodes are inserted at the head of each bucket’s list.
// Prints the final contents of all hash table buckets.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE];

void insert(int value) { 
    int i = value % SIZE;

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = value; 
    temp->next = hashTable[i]; 
    hashTable[i] = temp; 
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        printf("%d : ", i);
        struct Node *p = hashTable[i];

        if(p == NULL) {
            printf("\n");
            continue;
        }

        while(p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    int value[] = {12, 22, 32, 42, 52};
    int n = sizeof(value) / sizeof(value[0]);

    for(int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for(int i = 0; i < n; i++)
        insert(value[i]);

    display();

    return 0;
}
