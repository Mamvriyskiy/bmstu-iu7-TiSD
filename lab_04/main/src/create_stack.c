#include <stdio.h>
#include <stdlib.h>
#include "create_stack.h"
#include "main.h"
#include "stack_allocated.h"
#include "push_pop.h"
#include "errors.h"

int create_array_stack(array_stack_t *array_stack)
{
    int error = OK;
    if (array_stack->symbol != NULL)
        free_array_stack(array_stack);

    array_stack->symbol = allocated_array(MAX_LEN_STACK_ARRAY);
    if (array_stack->symbol == NULL)
        return -1;

    printf("\nВвод данных производится до перехода на новую строку(максимальная длина: %d).\n", MAX_LEN_STACK_ARRAY - 1);

    array_stack->size = 0;
    
    char value;
    fpurge(stdin);
    while ((value = getchar()) != '\n' && error == OK)
        error = push_array_stack(array_stack, value);
    
    printf("\nСтек упсешно создан!\n");

    return error;
}

int create_list_array(list_stack_t **list_stack, size_t *size_list)
{
    int error = OK;

    printf("\nВвод данных производится до перехода на новую строку.\n");
    
    char value;
    fpurge(stdin);
    while ((value = getchar()) != '\n' && error == OK)
    {
        error = push_list_stack(list_stack, value);
        if (error == OK)
            (*size_list)++;
    }

    printf("\nСтек упсешно создан!\n");
    
    return error;
}


