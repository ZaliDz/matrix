#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (s21_check_in_null(A) || s21_check_in_null(B)) {
    error = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    error = CALCULATION_ERROR;
  } else {
    error = s21_create_matrix(A->rows, B->columns, result);
    if (!error) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }
  return error;
}