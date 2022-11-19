#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "main.h"
#include "multiplication_matrix.h"
#include "create_matrix.h"
#include "output_information.h"

void multiplication_matrix(usuale_matrix_t *a, special_matrix_t *b, vector_matrix_t *c, usuale_matrix_t *result_a, special_matrix_t *result_b, usuale_matrix_t *vctr)
{
    int rc = OK;
    int num = -1;
    while (rc == OK)
    {
        print_information_multiplication();
        printf("\nВведите комманду: ");
        fpurge(stdin);
         
        if (scanf("%d", &num) != 1)
        {
            printf("\nДанные введены неверно.\n");
            continue;
        }

        switch (num)
        {
            case 1:
                multiplication_usuale_matrix(a, vctr, result_a, 1);
                break;
            case 2:
                multiplication_special_matrix(b, c, result_b, 1);
                break;
            case 0:
                rc = END_WORK_PROGRAMM;
                break;
        }
    }
}

int multiplication_usuale_matrix(usuale_matrix_t *a, usuale_matrix_t *c, usuale_matrix_t *result_a, int flag)
{
    int a_n = a->n;
    int a_m = a->m;

    int c_n = c->n;

    if (flag == 1 && a_m != c_n)
    {
        printf("\nУмножение провести невозможно. Разные размерности.\n");
        return -3;
    }

    result_a->data = allocated_matrix(a_m, 1);
    if (result_a->data == NULL)
        return -4;

    result_a->n = a_n;
    result_a->m = 1;

    for (int i = 0; i < a_n; i++)
    {
        for (int k = 0; k < a_m; k++)
            result_a->data[i][0] += a->data[i][k] * c->data[k][0]; 
    }

    if (flag == 1)
        print_result_matrix(result_a);

    return OK;
}

int multiplication_special_matrix(special_matrix_t *b, vector_matrix_t *c, special_matrix_t *result_b, int flag)
{
    int b_m = b->m;
    int b_n = b->n;
    
    int c_n = c->n;

    if (flag == 1 && b_m != c_n - 1)
    {
        printf("\nУмножение провести невозможно. Разные размерности.\n");
        return -3;
    }

    result_b->n = b_n;
    result_b->m = 1;

    if (alloc_special_matrix(result_b, b_m, b_n) != OK)
        return -4;

    initialization_zero(result_b->a, b_m);
    int index = 0;

    for (int i = 0; i < b_n; i++)
    {
        if (b->ia[i] != b->ia[i + 1])
        {
            int k = b->ia[i];
            while (k < b->ia[i + 1])
            {
                int pos = c->ja[b->ja[k]];
                if (pos != c->ja[b->ja[k] + 1])
                    result_b->a[index] += b->a[k] * c->a[pos];
                k++;
            }
        }
        index++;
        result_b->ia[i] = 0;
        result_b->ja[i] = i;
    }

    create_result(result_b);

    if (flag == 1)
        print_result_sp_matrix(result_b);
    return OK;
}

void initialization_zero(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

int create_result(special_matrix_t *result)
{
    int n = result->n;
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (result->a[i] == 0)
        {
            count++;
            if (result->a[i + 1] != 0)
                result->a[i] = result->a[i + 1];
        }
    }
    if (result->a[n - 1] == 0)
        count++;

    int *data = realloc(result->a, n - count);
    if (data == NULL)
        return -5;
    
    result->a = data;

    return OK;
}

void print_result_matrix(usuale_matrix_t *result_a)
{
    int a_n = result_a->n;

    for (int j = 0; j < a_n; j++)
        printf("%d\n", result_a->data[j][0]);
}

void print_result_sp_matrix(special_matrix_t *result_b)
{
    int a_n = result_b->n;

    for (int j = 0; j < a_n; j++)
        printf("%d\n", result_b->a[j]);
}
