// Hash Function Program
// ----------------------------
// Implements four hashing techniques for integer keys using a menu-driven approach.
//
// • k mod N: Returns key % N (simple and fast).  Time: O(1)
// • k mod 10: Uses last digit of key.            Time: O(1)
// • Mid-Square: Squares key and extracts middle digits for better distribution. Time: O(1)
// • Digit Folding: Splits key into equal digit groups, adds all groups, then applies % N. Time: O(d)
// The menu repeats until the user selects Exit. Each method computes and prints the hash value.

#include<stdio.h>

int midsquare(int key){
    int sq = key * key;
    int mid = (sq / 10) % 100;
    return mid;
}

int digit_folding(int key, int Size){
    if (Size <= 0) Size = 2;
    if (key < 0) key = -key;

    int sum = 0;
    int base = 1;

    for (int i = 0; i < Size; i++)
        base *= 10;

    while (key > 0){
        sum += key % base;   
        key /= base;        
    }
    return sum;
}

int main(){
    int key, choice, n;

    printf("Enter key: ");
    scanf("%d", &key);
    while (1){
        printf("\n---Hash Methods---\n");
        printf("1. k mod N\n");
        printf("2. k mod 10\n");
        printf("3. Mid-Square Method\n");
        printf("4. Digit Folding Method\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter no. of total keys (n): ");
                scanf("%d", &n);
                printf("Hash = %d\n", key % n);
                break;

            case 2:
                printf("Hash = %d\n", key % 10);
                break;

            case 3:
                printf("Hash (mid-square) = %d\n", midsquare(key));
                break;

            case 4: {
                int g;
                printf("Enter group size: ");
                scanf("%d", &g);

                printf("Enter no. of total keys (n): ");
                scanf("%d", &n);

                int folded = digit_folding(key, g);
                printf("Hash (digit-folding) = %d\n", folded % n);
                break;
            }

            case 5:
                printf("Exiting Program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
        }    

    return 0;
}
