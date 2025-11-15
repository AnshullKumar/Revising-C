
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

void transpose_matrix(int row, int col, int arr[row][col], int arr_T[col][row]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr_T[j][i] = arr[i][j];
        }
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
    
    int sparse_T[n][m];
    Zero_Mat(n, m, sparse_T);
    transpose_matrix(m, n, sparse, sparse_T);
    
    printf("This is the Transpose of the Sparse Matrix: \n");
    display_Matrix(n, m, sparse_T);
    
    return 0;
}