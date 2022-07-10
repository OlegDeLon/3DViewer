#ifndef SRC_PARSE_H_
#define SRC_PARSE_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 1e-07
#define N 1024

typedef enum {
  CORRECT_MATRIX = 0,
  INCORRECT_MATRIX = 1,
  IDENTITY_MATRIX = 2,
  ZERO_MATRIX = 3
} matrix_type_t;

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
  matrix_type_t matrix_type;
} matrix_t;

typedef struct arrays {
  float *vertexesarray;
  int n;
  int *facetsarray;
  int b;
  int vcount;
  int fcount;
} array_d;

typedef struct facets {
  int *vertexes;  // последовательность соединения вершин
  int numbers_of_vertexes_in_facets;  // количество вершин
} polygon_t;

typedef struct data {
  int count_of_vertexes;  // Количество вершин
  int count_of_facets;
  int count_of_facets_all;
  matrix_t matrix;
  polygon_t *polygons;
  array_d arrays;
} data_d;

void parse1(data_d *pdata, char *str);
void parse2(array_d *p_arrays, char *str);
matrix_t s21_create_matrix(int rows, int columns);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_mult_number(matrix_t *A, double number);
matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_transpose(matrix_t *A);
matrix_t s21_calc_complements(matrix_t *A);
matrix_t s21_inverse_matrix(matrix_t *A);
double s21_determinant(matrix_t *A);
double s21_common(matrix_t *A, int row, int column);
void s21_remove_matrix(matrix_t *A);
matrix_t s21_minimatrix(matrix_t *A, int a, int b);
int check_type(matrix_t *A);
void set_type(matrix_t *A);
#endif  //  SRC_PARSE_H_
