#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (s21_check_in_null(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else {
    if (s21_create_matrix(A->columns, A->rows, result) != OK) {
      error = INCORRECT_MATRIX;
    } else {
      s21_getCalc(A, result, &error);
    }
  }
  return error;
}