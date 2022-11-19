#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "push_pop.h"
#include "errors.h"

#define LENL 1000

int push_array_stack(array_stack_t *array_stack, char value)
{
    if (array_stack->size >= LENL)
        return -1;
    array_stack->symbol[array_stack->size] = value;
    array_stack->size++;

    return OK;
} 

int pop_array_stack(array_stack_t *array_stack, char *el)
{
    if (array_stack->size < 1)
        return -2;
    
    array_stack->size--;
    *el = array_stack->symbol[array_stack->size];
    
    return 0;
}

int push_list_stack(list_stack_t **head_list, char value)
{
    list_stack_t *tmp = malloc(sizeof(list_stack_t));
    if (tmp == NULL)
        return -4;

    tmp->next = *head_list;
    tmp->symbol = value;
    *head_list = tmp;

    return OK;
}

int pop_list_stack(list_stack_t **head_list)
{
    list_stack_t *tmp;
    char value = '\0';

    if (*head_list == NULL)
        return -4;

    tmp = *head_list;
    *head_list = (*head_list)->next;
    value = tmp->symbol;
    free(tmp);

    return value;
}
