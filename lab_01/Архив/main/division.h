#ifndef DIVISION_H
#define DIVISION_H

#include <stdio.h>

#define N_MAX 30

void division(int *num_1, int *num_2, int *result, int lenl_1, int lenl_2, int *exp);
void aligment(int *a, int size_zero, int lenl);
void print_array(const int *array, int array_size);
void move_digits(int *arr, int size);
void subtract(int *a, int *b, int size);
int comparison(int *a, int *b, int size);
void rounding(int *arr, int size, int last_digit);
void check_ten(int *arr_float, int *arr_int, int size, int *exp);

#endif