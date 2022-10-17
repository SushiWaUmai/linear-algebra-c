#include <stdio.h>
#include "matrix.h"

int main(void) {

  float a_data[] = {
    2, 3,
    5, 6
  };
  float b_data[] = {
    7, 8,
    1, 4
  };
  float c_data[] = {
    -1, 4,
    2, 1,
    -1, 2
  };
  float u_data[] = {
    2, 1
  };
  float v_data[] = {
    1,
    -2
  };

  Matrix *a = matrix_create_fill(2, 2, a_data);
  Matrix *b = matrix_create_fill(2, 2, b_data);
  Matrix *c = matrix_create_fill(3, 2, c_data);
  Matrix *u = matrix_create_fill(1, 2, u_data);
  Matrix *v = matrix_create_fill(2, 1, v_data);

  printf("a) \n");
  Matrix *pa = matrix_sub(a, b);
  matrix_print(pa);
  printf("\n");

  printf("b) \n");
  Matrix *pb = matrix_mul_s(matrix_transpose(c), 5);
  matrix_print(pb);
  printf("\n");

  printf("c) \n");
  Matrix *pc = matrix_mul_m(a, b); 
  matrix_print(pc);
  printf("\n");

  printf("d) \n");
  // Matrix *pd = matrix_mul_m(a, c); 
  // matrix_print(pd);
  printf("\n");

  printf("e) \n");
  Matrix *pe = matrix_mul_m(c, a); 
  matrix_print(pe);
  printf("\n");

  printf("f) \n");
  Matrix *pf = matrix_mul_m(u, a); 
  matrix_print(pf);
  printf("\n");

  printf("g) \n");
  Matrix *pg = matrix_mul_m(a, v); 
  matrix_print(pg);
  printf("\n");

  printf("h) \n");
  Matrix *ph = matrix_mul_m(u, v); 
  matrix_print(ph);
  printf("\n");

  printf("i) \n");
  Matrix *pi = matrix_mul_m(v, u); 
  matrix_print(pi);
  printf("\n");

  printf("j) \n");
  float pj = matrix_trace(a);
  printf("%f", pj);
  printf("\n");

  printf("k) \n");
  float pk = matrix_trace(b);
  printf("%f", pk);
  printf("\n");

  return 0;
}
