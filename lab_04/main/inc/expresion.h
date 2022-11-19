#ifndef _EXPRESION_H_
#define _EXPRESION_H_

#include "main.h"

#define MAX_LEN 10

int solve_arithmetic_expression();
int create_result_array(num_stack_t *num_stack, array_stack_t *el_stack, ssize_t read, char *line);
int check_el(char el);
void copy_stack(array_stack_t *array_stack, array_stack_t *copy_stack);
int pop_num_stack(num_stack_t *num_stack, int *el);
int push_num_stack(num_stack_t *num_stack, int value);
int power(int result, int b, char c);
int push_num_list_stack(num_stack_list_t **head_list, int value);
int pop_num_list_stack(num_stack_list_t **head_list, int *value);
int create_result_list(num_stack_list_t **num_stack, list_stack_t **el_stack, ssize_t read, char *line);

#endif
