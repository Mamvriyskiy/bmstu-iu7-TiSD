#ifndef _CREATE_VECTOR_H_
#define _CREATE_VECTOR_H_

#include "main.h"

void input_vector(vector_matrix_t *c, usuale_matrix_t *a);
int create_vector(vector_matrix_t *c, usuale_matrix_t *a);
void input_vector(vector_matrix_t *c, usuale_matrix_t *a);
int auto_create_vector(vector_matrix_t *c, usuale_matrix_t *a, int flag, int size);
void initialization_zero_matrix(int **data, int n, int m);
void make_special_vector(vector_matrix_t *c, usuale_matrix_t *a);

#endif
