#include <stdio.h>
#include "matrix.h"

int main(void) {
  float matrix_data1[3] = {
    1, 2, 3
  };

  float matrix_data2[3] = {
    2, -1, 0
  };

  Matrix *m1 = matrix_create(3, 1);
  Matrix *m2 = matrix_create(1, 3);

  matrix_fill(m1, matrix_data1);
  matrix_fill(m2, matrix_data2);

  Matrix *m3 = matrix_mul_m(m1, m2);

  matrix_print(m3);

  matrix_destroy(m1);
  matrix_destroy(m2);
  matrix_destroy(m3);
  return 0;
}
