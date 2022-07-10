#include "parse.h"

matrix_t s21_create_matrix(int rows, int columns) {
    matrix_t result;
    if (rows <= 0 || columns <= 0) {
        result.matrix_type = INCORRECT_MATRIX;
    } else {
        result.matrix_type = ZERO_MATRIX;
    }
    if (result.matrix_type == ZERO_MATRIX) {
    result.rows = rows;
    result.columns = columns;
    result.matrix = (double**)calloc(result.rows, sizeof(double*));
    for (int i = 0; i < result.rows; i++) {
        result.matrix[i] = (double*)calloc(result.columns, sizeof(double));
    }
  }
    return result;
}

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix_type != INCORRECT_MATRIX) {
        for (int i = 0; i < A->rows; i++) {
            free(A->matrix[i]);
        }
        free(A->matrix);
        A->matrix_type = INCORRECT_MATRIX;
    }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int result = FAILURE;
    if (A->matrix_type != INCORRECT_MATRIX &&
    B->matrix_type != INCORRECT_MATRIX) {
        if ((A->rows == B->rows) && (A->columns == B->columns)
        && (A->matrix_type == B->matrix_type)) {
            result = SUCCESS;
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
                        result = FAILURE;
                    }
                }
            }
        } else {
            result = FAILURE;
        }
    }
    return result;
}

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
    matrix_t result;
    if (A->matrix_type != INCORRECT_MATRIX &&
    B->matrix_type != INCORRECT_MATRIX &&
    A->rows == B->rows && A->columns == B->columns) {
            result = s21_create_matrix(A->rows, A->columns);
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    result.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                }
            }
        set_type(&result);
        } else {
            result.matrix_type = INCORRECT_MATRIX;
        }
    return result;
}

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
    matrix_t result;
    if (A->matrix_type != INCORRECT_MATRIX && B->matrix_type != INCORRECT_MATRIX
    && A->rows == B->rows && A->columns == B->columns) {
        result = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                result.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    set_type(&result);
    } else {
            result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}

matrix_t s21_mult_number(matrix_t *A, double number) {
    matrix_t result;
    if (A->matrix_type != INCORRECT_MATRIX) {
        result = s21_create_matrix(A->rows, A->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0 ; j < A->columns; j++) {
                result.matrix[i][j] = A->matrix[i][j] * number;
            }
        }
    set_type(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}

matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B) {
    matrix_t result;
    if (A->matrix_type != INCORRECT_MATRIX && B->matrix_type != INCORRECT_MATRIX
    && A->columns == B->rows) {
        result = s21_create_matrix(A->rows, B->columns);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                for (int k = 0; k < A->columns; k++) {
                    result.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                }
            }
        }
    set_type(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}

matrix_t s21_transpose(matrix_t *A) {
    matrix_t result;
    if (A->matrix_type != INCORRECT_MATRIX) {
        result = s21_create_matrix(A->columns, A->rows);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result.matrix[j][i] = A->matrix[i][j];
            }
        }
    set_type(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}

matrix_t s21_minimatrix(matrix_t *A, int a, int b) {
    matrix_t result;
    result = s21_create_matrix(A->rows - 1, A->columns - 1);
    for (int i = 0, _i = 0; i < result.rows; i++, _i++) {
        if (_i == a) _i++;

        for (int j = 0, _j = 0; j < result.columns; j++, _j++) {
            if (_j == b) _j++;

            result.matrix[i][j] = A->matrix[_i][_j];
        }
    set_type(&result);
    }
    return result;
}

double s21_determinant(matrix_t *A) {
    double det;
    if (A->rows != A->columns || A->matrix_type == INCORRECT_MATRIX) {
        det = NAN;
    } else {
        int size = A->columns;
        if (size == 2) {
        det = A->matrix[0][0] * A->matrix[1][1]
        - A->matrix[0][1] * A->matrix[1][0];
        } else if (size > 2) {
            det = 0;
            for (int i = 0; i < A->rows; i++) {
                det += A->matrix[0][i] * s21_common(A, 0, i);
            }
        }
        if (size == 1) det = A->matrix[0][0];
    }
    return det;
}

double s21_common(matrix_t *A, int row, int column) {
    double result;
    matrix_t minor = s21_minimatrix(A, row, column);
    result = pow(-1, column + row) * s21_determinant(&minor);
    s21_remove_matrix(&minor);
    return result;
}

matrix_t s21_calc_complements(matrix_t *A) {
    matrix_t result;
    if (A->matrix_type != INCORRECT_MATRIX && A->rows == A->columns) {
        result = s21_create_matrix(A->columns, A->rows);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result.matrix[i][j] = s21_common(A, i, j);
            }
        }
    set_type(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}

matrix_t s21_inverse_matrix(matrix_t *A) {
    matrix_t result;
    result.rows = A->rows;
    result.columns = A->columns;
    if (A->matrix_type != INCORRECT_MATRIX && A->rows == A->columns &&
    fabs(s21_determinant(A)) > EPSILON) {
        matrix_t calc = s21_calc_complements(A);
        matrix_t trans = s21_transpose(&calc);
        result = s21_mult_number(&trans, 1/s21_determinant(A));
        s21_remove_matrix(&calc);
        s21_remove_matrix(&trans);
        set_type(&result);
    } else {
        result.matrix_type = INCORRECT_MATRIX;
    }
    return result;
}

int check_type(matrix_t *A) {
    return (A->matrix_type != INCORRECT_MATRIX) ? SUCCESS : FAILURE;
}

void set_type(matrix_t *A) {
    if (A != NULL && check_type(A)) {
        int Iflag = 1, Zflag = 1;

        if (A->columns != A->rows) Iflag = 0;

        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (i == j && fabs(A->matrix[i][j] - 1.0) > EPSILON) Iflag = 0;
                if (i != j && fabs(A->matrix[i][j]) > EPSILON) Iflag = 0;
                if (fabs(A->matrix[i][j]) > EPSILON) Zflag = 0;
            }
        }
        if (A->rows == 0 || A->columns == 0) {
            A->matrix_type = INCORRECT_MATRIX;
        } else if (Iflag) {
            A->matrix_type = IDENTITY_MATRIX;
        } else if (Zflag) {
            A->matrix_type = ZERO_MATRIX;
        } else {
            A->matrix_type = CORRECT_MATRIX;
        }
    }
}
