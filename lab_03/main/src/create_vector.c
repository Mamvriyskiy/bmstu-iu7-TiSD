#include <stdio.h>
#include <stdlib.h>
#include <ranlib.h>
#include "errors.h"
#include "create_vector.h"
#include "create_matrix.h"
#include "output_information.h"
#include "main.h"


void input_vector(vector_matrix_t *c)
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
                create_vector(c);
                break;
            case 2:
                auto_create_vector(c);
                break;
            case 0:
                rc = END_WORK_PROGRAMM;
                break;
        }
    }
}

int create_vector(vector_matrix_t *c)
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
    c->n = a_n;
    c->k = a_k;

    int n, el;
    printf("\nВвод разряженного стобца-вектора: \n");
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

int auto_create_vector(vector_matrix_t *c)
{
    int a_n;

    printf("\nВведите количество строк матрицы: \n");

    if (scanf("%d", &a_n) != 1 || a_n <= 0 || a_n > 1000)
    {
        printf("Данные введены неверно.\n");
        return -3;
    }

    c->a = malloc(a_n * sizeof(int));
    c->ja = malloc(a_n * sizeof(int));
    c->n = a_n;
    c->k = a_n;

    for (int i = 0; i < a_n; i++)
    {
        c->a[i] = rand() % 100;
        c->ja[i] = i;
    }

    return OK;
}
