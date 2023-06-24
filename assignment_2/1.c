#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int matrix[MAX_ROWS][MAX_COLS];

int main() {
    int num_rows, num_cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &num_rows, &num_cols);

    // Read matrix elements from user
    printf("Enter matrix elements:\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print matrix
    printf("The matrix is:\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Read input number
    int num;
    printf("Enter a number to find neighbors: ");
    scanf("%d", &num);

    // Find location of number in matrix
    int row = -1, col = -1;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (matrix[i][j] == num) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1 && col != -1) {
            break;
        }
    }

    // Print neighbors of number in sorted order
    printf("Neighbors of %d are: ", num);
    int neighbors[8], num_neighbors = 0;
    if (row > 0 && col > 0) {
        neighbors[num_neighbors++] = matrix[row-1][col-1];
    }
    if (row > 0) {
        neighbors[num_neighbors++] = matrix[row-1][col];
    }
    if (row > 0 && col < num_cols-1) {
        neighbors[num_neighbors++] = matrix[row-1][col+1];
    }
    if (col > 0) {
        neighbors[num_neighbors++] = matrix[row][col-1];
    }
    if (col < num_cols-1) {
        neighbors[num_neighbors++] = matrix[row][col+1];
    }
    if (row < num_rows-1 && col > 0) {
        neighbors[num_neighbors++] = matrix[row+1][col-1];
    }
    if (row < num_rows-1) {
        neighbors[num_neighbors++] = matrix[row+1][col];
    }
    if (row < num_rows-1 && col < num_cols-1) {
        neighbors[num_neighbors++] = matrix[row+1][col+1];
    }
    // Sort neighbors using bubble sort
    for (int i = 0; i < num_neighbors-1; i++) {
        for (int j = 0; j < num_neighbors-i-1; j++) {
            if (neighbors[j] > neighbors[j+1]) {
                int temp = neighbors[j];
                neighbors[j] = neighbors[j+1];
                neighbors[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < num_neighbors; i++) {
        printf("%d ", neighbors[i]);
    }
    printf("\n");

    return 0;
}
