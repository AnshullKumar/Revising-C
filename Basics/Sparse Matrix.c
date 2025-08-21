// Sparse matrix representation in C
// it prints the non-zero elements of a matrix along with their indices



#include<stdio.h>

int main(){
    int rows, cols, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    int matrix[rows][cols];
    
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("The original matrix is:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("The sparse matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                printf("%d %d %d\n", i, j, matrix[i][j]);
            }
        }
    }

}