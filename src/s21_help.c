#include "s21_matrix.h"

int s21_check_in_null(matrix_t *A) {
  int error = OK;
  if (A == NULL || A->columns < 0 || A->rows < 0) {
    error = INCORRECT_MATRIX;
  }
  return error;
}

double s21_det_of_matrix(matrix_t *A, int size, int *error) {
  int sign = 1;
  double result = 0;
  *error = OK;
  if (size == 1) {
    result = A->matrix[0][0];
  } else if (size == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    matrix_t tmp = {0};
    if (s21_create_matrix(size, size, &tmp) != OK) {
      *error = INCORRECT_MATRIX;
    }
    for (int i = 0; i < size; i++) {
      s21_getCofactor(*A, &tmp, 0, i, size);
      result +=
          sign * A->matrix[0][i] * s21_det_of_matrix(&tmp, size - 1, error);
      sign = -sign;
    }
    s21_remove_matrix(&tmp);
  }
  return result;
}

void s21_getCofactor(matrix_t A, matrix_t *tmp, int skip_row, int skip_col,
                     int size) {
  int i = 0, j = 0;
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (row != skip_row && col != skip_col) {
        tmp->matrix[i][j++] = A.matrix[row][col];
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

void s21_getCalc(matrix_t *A, matrix_t *result, int *error) {
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
  } else {
    matrix_t tmp = {0};
    if (s21_create_matrix(A->columns, A->columns, &tmp) != OK) {
      *error = INCORRECT_MATRIX;
    }
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_getCofactor(*A, &tmp, i, j, A->rows);
        int sign = ((i + j) % 2 == 0) ? 1 : -1;
        result->matrix[i][j] =
            sign * s21_det_of_matrix(&tmp, A->rows - 1, error);
      }
    }
    s21_remove_matrix(&tmp);
  }
}