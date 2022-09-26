#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include "main.h"

#define LEN_ARRAY_NUMBER 11

int accumulation_struct_number(number_t *struct_number, char *number, int *mantissa_i, int *order_i);
size_t str_number_len(char *str);

void output_result(number_t *result_number, int lenl_mantissa);
void print(int *array, int i, int lenl);
int creat_number(int *a, int size);
int without_zero(int *array);


#endif
