#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (s21_check_in_null(A) || s21_check_in_null(B)) {
    error = FAILURE;
  } else if (A->rows != B->rows && A->columns != B->columns) {
    error = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > ACCURACY) {
          error = FAILURE;
          break;
        }
      }
      if (error == FAILURE) {
        break;
      }
    }
  }

  return error;
}