#include <stdio.h>
#include "main.h"
#include "print_stack.h"
#include "errors.h"
#include "push_pop.h"

void print_array_stack(array_stack_t *stack_array)
{
    printf("\nВывод элементов стэка: \n\n");

    int error = OK, k = 0;
    int copy_size = stack_array->size;

    char el;
    while (error == OK)
    {
        if (k < 3)
            k++;
        error = pop_array_stack(stack_array, &el);
        if (error == OK)
            printf("%c", el);
        if (k < 1)
            k++;
    }

    printf("\n");
    
    if (k == 1)
        printf("Стек пуст\n");

    stack_array->size = copy_size;
}

void print_list_array(list_stack_t *head_list)
{
    list_stack_t *copy_head = head_list;
    int k = 0;
    if (head_list == NULL)
        printf("\nРазмер массива равен 0.\n");
    else 
    {
        printf("\nВывод элементов стэка без адрессов: \n\n");
        while (head_list)
        {
            printf("%c", head_list->symbol);
            head_list = head_list -> next;
            k++;
        }

        printf("\n\nВывод элементов стэка с адрессами: \n\n");
        while (copy_head)
        {
            printf("%p %c\n", (void *) (copy_head), copy_head->symbol);
            copy_head = copy_head ->next;
            k++;
        }
    printf("\n");
    }
    
    if (k == 0)
        printf("\nСтек пуст\n");
}

int print_free_areas(free_areas_t *free_areas)
{
    printf("\nВывод адрессов удаленных элементов: \n");
    if (free_areas->len == 0)
    {
        printf("\nЭлементы не удалялись, либо память освобождена.\n");
        return -4;
    }

    for (int i = 0; i < free_areas->len; i++)
        printf("%p\n", (void *) free_areas->arr[i]);

    return OK;
}

