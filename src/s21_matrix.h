#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define SUCCESS 1
#define FAILURE 0
#define ACCURACY 1e-06

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum errors { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_check_in_null(matrix_t *A);
void s21_getCofactor(matrix_t A, matrix_t *tmp, int move_column, int move_row,
                     int size);
double s21_det_of_matrix(matrix_t *A, int size, int *error);
void s21_getCalc(matrix_t *A, matrix_t *result, int *error);

#endif