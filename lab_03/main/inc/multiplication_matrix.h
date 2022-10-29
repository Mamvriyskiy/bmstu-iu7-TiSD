#ifndef _MULTIPLICATION_MATRIX_H_
#define _MULTIPLICATION_MATRIX_H_

#include "main.h"

void multiplication_matrix(usuale_matrix_t *a, special_matrix_t *b, vector_matrix_t *c, usuale_matrix_t *result_a, special_matrix_t *result_b);
int multiplication_usuale_matrix(usuale_matrix_t *a, vector_matrix_t *c, usuale_matrix_t *result_a);
void print_result_usuale_matrix(usuale_matrix_t *result_a);
int multiplication_sepical_matrix(special_matrix_t *b, vector_matrix_t *c, special_matrix_t *result_b);
void initialization_zero(int *a, int n);
int create_result(special_matrix_t *result);

#endif
