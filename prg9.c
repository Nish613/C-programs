#include <stdio.h>
#include <stdlib.h>

int **matrix(int row, int col) {
    int **mat = (int **)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
        *(mat + i) = (int *)malloc(col * sizeof(int));
    return mat;   
}

void displayMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", *(*(mat + i) + j));
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **mat = matrix(rows, cols);

    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            scanf("%d", *(mat + i) + j);
    }

    printf("Matrix:\n");
    displayMatrix(mat, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++)
        free(*(mat + i));
    free(mat);

    return 0;
}
