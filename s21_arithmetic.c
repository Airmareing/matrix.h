#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int check = s21_check_size_of_matrices(A, B, 0);
    if (!check) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (A->matrix[i][j] != B->matrix[i][j])
                    check = 0;
            }
        }
    }
    return check;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int check = s21_check_size_of_matrices(A, B, 0);
    if (!check) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }
    return check;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int check = s21_check_size_of_matrices(A, B, 0);
    if (!check) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }
    return check;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] * number;
        }
    }
    return 0; // посмотреть, что выдаёт
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int check = s21_check_size_of_matrices(A, B, 1);
    if (!check) {
        for (int i = 0; i < B->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                int k = 0;
                while (k < B->rows) {
                    result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                    k++;
                }
            }
        }
    }
    return check;
}

int s21_check_size_of_matrices(matrix_t *A, matrix_t *B, int mult_matrix) {
    int res = 0;
    //printf("ok");
    if ((mult_matrix == 0) && ((A->rows != B->rows) || (A->columns != B->columns))) {
        res = 2;
    } else if ((mult_matrix == 1) && (A->columns != B->rows)) {
        res = 2;
    }
    return res;
}