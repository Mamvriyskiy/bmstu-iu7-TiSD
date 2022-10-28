#ifndef _CREATE_MATRIX_H_
#define _CREATE_MATRIX_H_

#include "main.h"

int create_usuale_matrix(usuale_matrix_t *a, special_matrix_t *b);
int **allocated_matrix(const int n, const int m);
void make_special_matrix(usuale_matrix_t *a, special_matrix_t *b);
int create_special_matrix(usuale_matrix_t *a, special_matrix_t *b);
int check_position(int *a, int *b, int count, int n, int m);
int auto_create_matrix(usuale_matrix_t *a, special_matrix_t *b);
int alloc_special_matrix(special_matrix_t *b, int count);

#endif

