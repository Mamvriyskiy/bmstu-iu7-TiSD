#include <stdio.h>
#include <stdlib.h>
#include "stack_allocated.h"
#include "main.h"


char *allocated_array(int size_array)
{
    char *data = (char *) malloc(size_array * sizeof(char));
    if (!data)
        return NULL;
    
    return data;
}

void free_array_stack(array_stack_t *array_stack)
{
    free(array_stack->symbol);
    array_stack->size = 0;
    array_stack->symbol = NULL;
}
