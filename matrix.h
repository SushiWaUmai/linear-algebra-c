#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
  int columns, rows;
  float *values;
} Matrix;

Matrix *matrix_create(int rows, int columns);
Matrix *matrix_create_fill(int rows, int colums, float *data);
Matrix *matrix_create_identity(int size);
void matrix_destroy(Matrix *target);

void matrix_fill(Matrix *target, float *data);
void matrix_print(Matrix *target);

Matrix *matrix_add(Matrix *m1, Matrix *m2);
Matrix *matrix_sub(Matrix *m1, Matrix *m2);
Matrix *matrix_mul_s(Matrix *target, float value);
Matrix *matrix_mul_m(Matrix *m1, Matrix *m2);

float matrix_trace(Matrix *target);
Matrix *matrix_transpose(Matrix *target);

#endif // MATRIX_H
