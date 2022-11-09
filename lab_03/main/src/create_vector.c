#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "create_vector.h"
#include "create_matrix.h"
#include "output_information.h"
#include "main.h"
#include "multiplication_matrix.h"

void input_vector(vector_matrix_t *c, usuale_matrix_t *a)
{
    int rc = OK;
    int num = -1;
    while (rc == OK)
    {
        print_inform_about_vector();
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
                create_vector(c, a);
                break;
            case 2:
                auto_create_vector(c, a, 1, 0);
                break;
            case 0:
                rc = END_WORK_PROGRAMM;
                break;
        }
    }
}

int create_vector(vector_matrix_t *c, usuale_matrix_t *a)
{
    int a_n, a_k;

    printf("\nВведите количество строк матрицы: \n");

    if (scanf("%d", &a_n) != 1 || a_n <= 0 || a_n > 1000)
    {
        printf("Данные введены неверно.\n");
        return -3;
    }

    printf("\nВведите количество ненулевых элементов матрицы: \n");
    if (scanf("%d", &a_k) != 1 || a_k < 0 || a_k > a_n)
    {
        printf("Данные введены неверно.\n");
        return -3;
    }

    c->a = malloc(a_k * sizeof(int));
    c->ja = malloc(a_k * sizeof(int));
    a->data = allocated_matrix(a_n , 1);
    c->n = a_n;
    c->k = a_k;
    a->m = 1;
    a->n = a_n;

    int n, el;
    printf("\nВвод разряженного стобца-вектора: \n");
    initialization_zero_matrix(a->data, a_n, 1);

    for (int i = 0; i < a_k; i++)
    {
        int rc = -1;
        while (rc != OK)
        {
            fpurge(stdin);
            printf("\nВведите %d элемент(строка элемент).\n", i + 1);

            if (scanf("%d %d", &n, &el) == 2)
            {
                if (check_position_vector(c->ja, i, n - 1) == OK)
                {
                    if (el == 0 || n < 1 || n > a_n)
                        printf("\nНомер строки введен неверно(Строка: 1 - %d).\n", a_n);
                    else
                    {
                        c->a[i] = el;
                        c->ja[i] = n - 1;
                        a->data[n - 1][0] = el;
                        rc = OK;
                    }
                }
                else 
                    printf("\nДанные уже были введены.\n");
            }
            else
                printf("\nДанные введены неверно.\n");
        }
    }

    return OK;
}

int check_position_vector(int *c, int count, int n)
{
    for (int i = 0; i < count; i++)
    {
        if (c[i] == n)
            return -3;
    }

    return OK;
}

int auto_create_vector(vector_matrix_t *c, usuale_matrix_t *a, int flag, int size)
{
    int a_n;

    if (flag == 1)
    {
        printf("\nВведите количество строк вектора: \n");

        if (scanf("%d", &a_n) != 1 || a_n <= 0 || a_n > 1000)
        {
            printf("Данные введены неверно.\n");
            return -3;
        }
    }
    else
        a_n = size;

    c->a = malloc(a_n * sizeof(int));
    c->ja = malloc(a_n * sizeof(int));
    a->data = allocated_matrix(a_n , 1);
    c->n = a_n;
    c->k = a_n;
    a->m = 1;
    a->n = a_n;

    initialization_zero_matrix(a->data, a_n, 1);

    for (int i = 0; i < a_n; i++)
    {
        int el = rand() % 100;
        c->a[i] = el;
        c->ja[i] = i;
        a->data[i][0] = el;
    }

    return OK;
}

void initialization_zero_matrix(int **data, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            data[i][j] = 0;
    }
}
