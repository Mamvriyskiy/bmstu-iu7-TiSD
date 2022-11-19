#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "add_delete.h"
#include "errors.h"
#include "push_pop.h"
#include "stack_allocated.h"

int add_new_element_array_stack(array_stack_t *array_stack)
{
    if (array_stack->size == 0)
        array_stack->symbol = allocated_array(MAX_LEN_STACK_ARRAY);

    int error = OK, num = -1;
    while (error == OK)
    {

        printf("\nВведите количество новых элементов(доступно %d). Для выхода введите '0': ", MAX_LEN_STACK_ARRAY - array_stack->size - 1);
        fpurge(stdin);
         
        if (scanf("%d", &num) != 1 || num < 0)
        {
            printf("\nДанные введены неверно.\n");
            continue;
        }
        else if (num + array_stack->size >= MAX_LEN_STACK_ARRAY)
        {
            printf("\nСтек будет переполнен.\n");
            continue;
        }
        else if (num == 0)
            return OK;
        else 
            break;
    }

    char value;
    printf("\nВвод будет осуществляться до знака перехода строки или до указанного количества чисел.\n");
    printf("Введите элементы(%d):\n", num);

    int i = 0;
    fpurge(stdin);
    while ((value = getchar()) != '\n' && error == OK && i < num)
    {
        error = push_array_stack(array_stack, value);
        i++;
    }

    return OK;
}

int delete_element_array_stack(array_stack_t *array_stack)
{
    int error = OK, num = -1;
    while (error == OK)
    {

        printf("\nВведите количество элементовдля удаления(доступно %d). Для выхода введите '0': ", array_stack->size);
        fpurge(stdin);
         
        if (scanf("%d", &num) != 1 || num < 0)
        {
            printf("\nДанные введены неверно.\n");
            continue;
        }
        else if (array_stack->size - num < 0)
        {
            printf("\nКоличество элементов превышает размер стека(%d).\n", array_stack->size);
            continue;
        }
        else if (num == 0)
            return OK;
        else 
            break;
    }

    array_stack->size -= num;
    printf("\nЭлементы удалены\n");

    return OK;
}

int add_new_element_list(list_stack_t **stack_list, size_t *size_list)
{
    printf("\nВвод будет осуществляться до знака перехода на новую строки.\n");

    char value;
    int error = OK;
    fpurge(stdin);

    while ((value = getchar()) != '\n' && error == OK)
    {
        error = push_list_stack(stack_list, value);
        (*size_list)++;
    }

    return OK; 
}

int delete_list_array(list_stack_t **head_list, size_t *size_list, free_areas_t *free_areas)
{
    int error = OK, num = -1;
    while (error == OK)
    {

        printf("\nВведите количество элементов для удаления(доступно %zu). Для выхода введите '0': ", *size_list);
        fpurge(stdin);
         
        if (scanf("%d", &num) != 1 || num < 0)
        {
            printf("\nДанные введены неверно.\n");
            continue;
        }
        else if (*size_list - num < 0)
        {
            printf("\nКоличество элементов превышает размер стека(%zu).\n", *size_list);
            continue;
        }
        else if (num == 0)
            return OK;
        else 
            break;
    }

    printf("\nЭлементы удалены\n");

    memset(free_areas->arr, 0, sizeof(free_areas->arr));
    free_areas->len = 0;
    for (int i = 0; i < num; i++)
    {
        free_areas->arr[free_areas->len] = *head_list;
        free_areas->len++;
        *head_list = (*head_list)->next;
        (*size_list)--;
    }

    return OK;
}
