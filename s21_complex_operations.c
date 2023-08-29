#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[j][i];
        }
    }
    return 0;
}

//int s21_calc_complements(matrix_t *A, matrix_t *result) {}

int s21_determinant(matrix_t *A, double *result) {
    int check = 0;
    if (A->columns != A->rows) {
        check = 1;
    } else {
        int minor_col = A->columns;
        int minor_row = A->rows;
        while((minor_col > 2) && (minor_row > 2)) {
            for (int count = 0; count < minor_row; count++) {
                matrix_t minor; 
                double next_minor = 0; // сюда запишем результат для рекурсии
                minor.rows = minor_row - 1;
                minor.columns = minor_col - 1;
                s21_get_minor(A, &minor, count); // заполняем минор
                s21_determinant(&minor, &next_minor); // рекурсия
                *result += (A->matrix[count][1] * next_minor); // добавляем результат
            }
        }
        if ((minor_col == 2) && (minor_row == 2)) {
            *result += ((A->matrix[1][1] * A->matrix[2][2]) - (A->matrix[1][2] * A->matrix[2][1]));
        }
    }
    return check;
}

void s21_get_minor(matrix_t *A, matrix_t *minor, int current) {
    for (int i = 0; i < A->rows; i++) {
        if (current != i) { // убираем строки 
            for (int j = 1; j < A->columns; j++) { // будет всегда убираться первый столбец, т к переписываем минор
                minor->matrix[i][j] = A->matrix[i][j];
            }
        }
    } 
}
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
