#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (s21_check_in_null(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else {
    *result = s21_det_of_matrix(A, A->rows, &error);
  }
  return error;
}
