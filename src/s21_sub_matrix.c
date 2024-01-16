#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (s21_check_in_null(A) || s21_check_in_null(B)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error = CALCULATION_ERROR;
  } else {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (!error) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return error;
}