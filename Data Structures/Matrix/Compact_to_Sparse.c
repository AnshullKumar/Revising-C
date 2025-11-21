// Compact-to-Sparse Converter
// ---------------------------
// This Program converts the Compact Form to its Sparse Matrix representation.
// • Converts a dense 2D matrix into a compact sparse representation.
// • Scans the matrix with two nested loops and stores only non-zero entries
// (positions + values) in compact arrays/structures.
// • Time Complexity: O(rows * cols)
// Space Complexity: O(nnz) where nnz is the number of non-zero elements.

#include<stdio.h>

void Zero_Mat(int row, int col, int arr[row][col]){
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j] = 0;
        }
    }
}

void COO_to_Sparse(int row[], int col[], int val[], int non_zero, int m, int n, int arr[m][n]){
    for(int i = 0; i < non_zero; i++){
            arr[row[i]][col[i]] = val[i];
        }
}

void display_Matrix(int row, int col, int arr[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m, n, non_zero;
    printf("Enter no. of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter no. of Non-Zero elements present in the matrix: ");
    scanf("%d", &non_zero);
    
    int row[non_zero], col[non_zero], val[non_zero], sparse[m][n];
    
    printf("Enter COO Representation of the elements: ");
    for(int i = 0; i < non_zero; i++){
        scanf("%d %d %d", &row[i], &col[i], &val[i]);
    }
    
    Zero_Mat(m, n, sparse);
    COO_to_Sparse(row, col, val, non_zero, m, n, sparse);
    
    printf("This is the Sparse Matrix: \n");
    display_Matrix(m, n, sparse);
    
    return 0;
}