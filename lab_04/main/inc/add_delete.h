#ifndef _ADD_DELETE_H_
#define _ADD_DELETE_H_

#include "main.h"

int add_new_element_array_stack(array_stack_t *array_stack);
int delete_element_array_stack(array_stack_t *array_stack);
int add_new_element_list(list_stack_t **stack_list, size_t *size_list);
int delete_list_array(list_stack_t **head_list, size_t *size_list, free_areas_t *free_areas);

#endif
