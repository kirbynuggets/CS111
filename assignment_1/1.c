#include <stdio.h>

#define N 3

int trace(int mat[N][N])
 {
    int tr = 0;
    for (int i = 0; i < N; i++) {
        tr += mat[i][i];
    }
    return tr;
}

void transpose(int mat[N][N], int trans[N][N])
 {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            trans[i][j] = mat[j][i];
        }
    }
}


void matMul(int A[N][N], int B[N][N], int A_B[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A_B[i][j] = 0;
            for (int k = 0; k < N; k++) {
                A_B[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int is_singular(int mat[N][N]) {
    int det = 0;
    for (int i = 0; i < N; i++) {
        det += (mat[0][i] * (mat[1][(i+1)%N] * mat[2][(i+2)%N] - mat[1][(i+2)%N] * mat[2][(i+1)%N]));
    }
    if (det == 0)
        printf("Singular");
    else
        printf("Not singular");
}

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}};
    int At[N][N], Bt[N][N], AtB[N][N];

    // trace of A and B
    int trA = trace(A);
    int trB = trace(B);

    printf("Trace of A: %d\n", trA);
    printf("Trace of B: %d\n", trB);

    // transpose of A and B
    transpose(A, At);
    transpose(B, Bt);

    printf("Transpose of A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", At[i][j]);
        }
        printf("\n");
    }

    printf("Transpose of B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", Bt[i][j]);
        }
        printf("\n");
    }

    // multiplication of A transpose and B
    matMul(At, B, AtB);

    printf("multiplication of A transpose B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", AtB[i][j]);
        }
        printf("\n");
    }

    // Verifying if A transpose and B is singular
    printf("A transpose B is: ");
    is_singular(AtB);
    printf("\n");
}
