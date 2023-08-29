#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for(int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)malloc(columns * sizeof(double));
    }
    return 0;
}

void s21_remove_matrix(matrix_t *A) {
    for(int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
    }
    free(A->matrix);
}

int main() {
    int N = 3, M = 3;
    int R = 3, H = 3;
    
    // объявление
    matrix_t test;
    matrix_t test2;
    matrix_t result;

    // создание
    s21_create_matrix(N, M, &test);
    s21_create_matrix(R, H, &test2);
    s21_create_matrix(N, H, &result);

    // заполнение
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%lf", &test.matrix[i][j]); 
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < H; j++) {
            scanf("%lf", &test2.matrix[i][j]); 
        }
    }

    // вывод
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.8lf ", test.matrix[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < H; j++) {
            printf("%.8lf ", test2.matrix[i][j]); 
        }
        printf("\n");
    }

    
    printf("\nsum %d\n", s21_sum_matrix(&test, &test2, &result));
    //printf("\nequal %d\n", s21_eq_matrix(&test, &test2));
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.8lf ", result.matrix[i][j]); 
        }
        printf("\n");
    }
    printf("\nsub %d\n", s21_sub_matrix(&test, &test2, &result));
    //printf("\nequal %d\n", s21_eq_matrix(&test, &test2));
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.8lf ", result.matrix[i][j]); 
        }
        printf("\n");
    }
    
    printf("\nmult %d\n", s21_mult_matrix(&test, &test2, &result));
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < H; j++) {
            printf("%.8lf ", result.matrix[i][j]); 
        }
        printf("\n");
    }
    // удаление
    s21_remove_matrix(&test);
    s21_remove_matrix(&test2);
}
