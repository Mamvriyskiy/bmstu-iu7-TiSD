#ifndef _CHECK_TIME_H_
#define _CHECK_TIME_H_

#include "main.h"

int check_time();
void test_auto_create_matrix(usuale_matrix_t *a, special_matrix_t *b, usuale_matrix_t *res_a, special_matrix_t *res_b, int lenl);
void test_auto_create_vector(vector_matrix_t *c, usuale_matrix_t *vctr, int lenl);
void check_multiplication_special_matrix(special_matrix_t *b, vector_matrix_t *c, special_matrix_t *result_b);
void check_multiplication_usuale_matrix(usuale_matrix_t *a, usuale_matrix_t *c, usuale_matrix_t *result_a);

#endif
