#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

Matrix *matrix_create(int rows, int columns) {
  Matrix *result = (Matrix *)malloc(sizeof(Matrix));
  result->rows = rows;
  result->columns = columns;
  result->values = (float *)malloc(rows * columns * sizeof(float));
  memset(result->values, 0, rows * columns * sizeof(float));
  return result;
}

Matrix *matrix_create_fill(int rows, int colums, float *data) {
  Matrix *result = matrix_create(rows, colums);
  matrix_fill(result, data);
  return result;
}

Matrix *matrix_create_identity(int size) {
  Matrix *result = matrix_create(size, size);

  for (int i = 0; i < size; i++) {
    result->values[i * size + i] = 1;
  }
  
  return result;
}

void matrix_destroy(Matrix *target) {
  free(target->values);
  free(target);
}

void matrix_fill(Matrix *target, float *data) {
  memcpy(target->values, data, target->columns * target->rows * sizeof(float));
}

void matrix_print(Matrix *target) {
  for (int r = 0; r < target->rows; r++) {
    for (int c = 0; c < target->columns; c++) {
      printf("%.3f\t", target->values[r * target->columns + c]);
    }
    printf("\n");
  }
}

Matrix *matrix_add(Matrix *m1, Matrix *m2) {
  // Check if dimensions are correct
  assert(m1->columns == m2->columns && m1->rows == m2->rows);
  Matrix *result = matrix_create(m1->rows, m1->columns);

  for (int r = 0; r < result->rows; r++) {
    for (int c = 0; c < result->columns; c++) {
      result->values[r * result->columns + c] = m1->values[r * result->columns + c] + m2-> values[r * result->columns + c];
    }
  }

  return result;
}

Matrix *matrix_sub(Matrix *m1, Matrix *m2) {
  // Check if dimensions are correct
  assert(m1->rows == m2->rows && m1->columns == m2->columns);
  Matrix *result = matrix_create(m1->rows, m1->columns);

  for (int r = 0; r < result->rows; r++) {
    for (int c = 0; c < result->columns; c++) {
      result->values[r * result->columns + c] = m1->values[r * result->columns + c] - m2-> values[r * result->columns + c];
    }
  }

  return result;
}

Matrix *matrix_mul_s(Matrix *target, float value) {
  Matrix *result = matrix_create(target->rows, target->columns);

  for (int r = 0; r < result->rows; r++) {
    for (int c = 0; c < result->columns; c++) {
      result->values[r * result->columns + c] = target->values[r * result->columns + c] * value;
    }
  }

  return result;
}

Matrix *matrix_mul_m(Matrix *m1, Matrix *m2) {
  assert(m1->columns == m2->rows);
  Matrix *result = matrix_create(m1->rows, m2->columns);

  for (int r = 0; r < m1->rows; r++) {
    for (int c = 0; c < m2->columns; c++) {
      for (int i = 0; i < m2->rows; i++) {
        result->values[r * m2->columns + c] += m1->values[r * m1->columns + i] * m2->values[m2->columns * i + c];
      }
    }
  }

  return result;
}

float matrix_trace(Matrix *target) {
  assert(target->columns == target->rows);
  float result = 0;

  for (int i = 0; i < target->rows; i++) {
    result += target->values[i * target->rows + i];
  }

  return result;
}

Matrix *matrix_transpose(Matrix *target) {
  Matrix *result = matrix_create(target->columns, target->rows);

  for (int r = 0; r < target->rows; r++) {
    for (int c = 0; c < target->columns; c++) {
      result->values[c * target->rows + r] = target->values[r * target->columns + c];
    }
  }

  return result;
}

