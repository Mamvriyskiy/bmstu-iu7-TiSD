#ifndef _MULTIPLICATION_MATRIX_H_
#define _MULTIPLICATION_MATRIX_H_

#include "main.h"

void multiplication_matrix(usuale_matrix_t *a, special_matrix_t *b, vector_matrix_t *c, usuale_matrix_t *result_a, special_matrix_t *result_b, usuale_matrix_t *vctr);
int multiplication_usuale_matrix(usuale_matrix_t *a, usuale_matrix_t *c, usuale_matrix_t *result_a, int flag);
void print_result_matrix(usuale_matrix_t *result_a);
int multiplication_special_matrix(special_matrix_t *b, vector_matrix_t *c, special_matrix_t *result_b, int flag);
void initialization_zero(int *a, int n);
int create_result(special_matrix_t *result);
void print_result_sp_matrix(special_matrix_t *result_b);

#endif
