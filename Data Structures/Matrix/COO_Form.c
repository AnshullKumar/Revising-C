// COO Form Converter
// ------------------
// This is the Compact Form of a Sparse Matrix
// • Converts a dense 2D matrix to COO (Coordinate) sparse format.
// • Scans the matrix with two nested loops and records non-zero entries
// into parallel arrays: row[], col[], val[].
// • Time Complexity: O(rows * cols)
// Space Complexity: O(nnz) where nnz is the number of non-zero elements.


#include<stdio.h>

void COOform(int row, int col, int arr[row][col]){
    
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] != 0) printf("[%d %d %d] \n", i, j, arr[i][j]);
        }
    }
}

int main(){
    int m, n;
    printf("Enter row and columm: ");
    scanf("%d %d", &m, &n);
    
    int arr[m][n];
    printf("Enter the %d x %d matrix: ", m, n);
 
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) scanf("%d ", &arr[i][j]);
    }
    COOform(m, n, arr);
    return 0;
}