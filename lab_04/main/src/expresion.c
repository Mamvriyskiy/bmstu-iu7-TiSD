#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "expresion.h"
#include "main.h"
#include "errors.h"
#include "push_pop.h"
#include "print_stack.h"
#include "stack_allocated.h"

int solve_arithmetic_expression()
{
    int error = OK;

    num_stack_t num_stack;
    num_stack.size = 0;

    array_stack_t el_stack;
    el_stack.size = 0;

    el_stack.symbol = allocated_array(MAX_LEN_STACK_ARRAY);
    if (el_stack.symbol == NULL)
        return -2;

    num_stack_list_t *num_stack_list = NULL;

    list_stack_t *el_stack_list = NULL;

    printf("\nВвод данных производится до перехода на новую строку(максимальная длина: %d).\n", MAX_LEN_STACK_ARRAY - 1);
    
    ssize_t read;
    char *line = NULL;
    size_t len = 0;

    fpurge(stdin);
    if ((read = getline(&line, &len, stdin)) == -1)
        return -1;

    clock_t start, end;

    start = clock();
    create_result_array(&num_stack, &el_stack, read, line);
    end = clock();
    printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);  

    printf("\n");

    start = clock();
    create_result_list(&num_stack_list, &el_stack_list, read, line);
    end = clock();
    
    printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
 
    return error;
}

int create_result_array(num_stack_t *num_stack, array_stack_t *el_stack, ssize_t read, char *line)
{
    int num = 0;

    char last_el;

    for (ssize_t i = 0; i < read; i++)
    {
        if (check_el(line[i]) == OK)
        {
            num = num * 10 + (line[i] - '0');
        }
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
        {
            push_num_stack(num_stack, num);
            num = 0;
            if (last_el == '*' || last_el == '/')
            {
                int a, b;
                pop_num_stack(num_stack, &a);
                pop_num_stack(num_stack, &b);

                if (last_el == '*')
                    a *= b;
                else
                {
                    if (b == 0 && line[i] == '/')
                    {
                        printf("На ноль делить нельзя.");
                        return -3;
                    }
                    a /= b;
                }

                // char c;
                // pop_array_stack(el_stack, &c);
                push_num_stack(num_stack, a);
            }
            push_array_stack(el_stack, line[i]);
            last_el = line[i];
        }
        else if (i + 1 == read)
            push_num_stack(num_stack, num);
        else
        {
            printf("Данные введены неверно\n");
            return -4;
        }
    }

    int result, flag = 0;
    char c;
    while (num_stack->size)
    {
        int b;
        if (flag == 0)
        {
            pop_num_stack(num_stack, &result);
            flag = 1;
        }

        pop_num_stack(num_stack, &b);
        pop_array_stack(el_stack, &c);
        
        if (result == 0 && c == '/')
        {
            printf("Деление на ноль.");
            return -3;
        }

        result = power(result, b, c);
    }

    printf("Result: %d\n", result);
    return OK;
}

int create_result_list(num_stack_list_t **num_stack, list_stack_t **el_stack, ssize_t read, char *line)
{
    int num = 0;

    char last_el;

    for (ssize_t i = 0; i < read; i++)
    {
        if (check_el(line[i]) == OK)
        {
            num = num * 10 + (line[i] - '0');
        }
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
        {
            push_num_list_stack(num_stack, num);
            num = 0;
            if (last_el == '*' || last_el == '/')
            {
                int a, b;
                pop_num_list_stack(num_stack, &a);
                pop_num_list_stack(num_stack, &b);

                if (last_el == '*')
                    a *= b;
                else
                {
                    if (b == 0 && line[i] == '/')
                    {
                        printf("На ноль делить нельзя.");
                        return -3;
                    }
                    a /= b;
                }

                // char c = pop_list_stack(el_stack);
                push_num_list_stack(num_stack, a);
            }
            push_list_stack(el_stack, line[i]);
            last_el = line[i];
        }
        else if (i + 1 == read)
            push_num_list_stack(num_stack, num);
        else
        {
            printf("Данные введены неверно\n");
            return -4;
        }
    }

    int result, flag = 0;
    char c;
    int error = OK;
    while (error == OK)
    {
        int b;
        if (flag == 0)
        {
            error = pop_num_list_stack(num_stack, &result);
            flag = 1;
        }

        error = pop_num_list_stack(num_stack, &b);
        if (error != OK)
            break;

        c = pop_list_stack(el_stack);
        // printf("%d %c %d", result, c, b);
        
        if (result == 0 && c == '/')
        {
            printf("Деление на ноль.");
            return -3;
        }

        result = power(result, b, c);
    }

    printf("Result: %d\n", result);

    return OK;
}

int power(int result, int b, char c)
{
    if (c == '-')
        result = b - result;
    else if (c == '+')
        result += b;
    else if (c == '*')
        result *= b;
    else if (result != 0)
        result = b / result;
    return result;
}


int check_el(char el)
{
    char num[MAX_LEN] = "0123456789";
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (el == num[i])
            return OK;
    }

    return -1;
}

int pop_num_stack(num_stack_t *num_stack, int *el)
{
    if (num_stack->size < 1)
        return -2;
    
    num_stack->size--;
    *el = num_stack->num[num_stack->size];
    
    return 0;
}

int push_num_stack(num_stack_t *num_stack, int value)
{
    if (num_stack->size >= MAX_LEN_STACK_ARRAY)
        return -1;
    num_stack->num[num_stack->size] = value;
    num_stack->size++;

    return OK;
} 

int push_num_list_stack(num_stack_list_t **head_list, int value)
{
    num_stack_list_t *tmp = malloc(sizeof(num_stack_list_t));
    if (tmp == NULL)
        return -4;

    tmp->next = *head_list;
    tmp->symbol = value;
    *head_list = tmp;

    return OK;
}

int pop_num_list_stack(num_stack_list_t **head_list, int *value)
{
    num_stack_list_t *tmp;

    if (*head_list == NULL)
        return -4;

    tmp = *head_list;
    *head_list = (*head_list)->next;
    *value = tmp->symbol;
    free(tmp);

    return OK;
}


