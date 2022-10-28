#include <stdio.h>
#include <stdlib.h>
#include <ranlib.h>
#include "errors.h"
#include "create_matrix.h"
#include "main.h"

int create_usuale_matrix(usuale_matrix_t *a, special_matrix_t *b)
{
    int a_n, a_m;

    printf("\nВведите количество строк матрицы: \n");

    if (scanf("%d", &a_n) != 1 || a_n <= 0 || a_n > 1000)
    {
        printf("Данные введены неверно.\n");
        return -3;
    }

    printf("\nВведите количество столбцов матрицы: \n");

    if (scanf("%d", &a_m) != 1 || a_m <= 0 || a_m > 1000)
    {
        printf("Данные введены неверно.\n");
        return -3;
    }

    a->n = a_n;
    a->m = a_m;

    b->n = a_n;
    b->m = a_m;
    
    a->data = allocated_matrix(a_n, a_m);
    if (a->data == NULL)
        return -4;


    printf("Ввод элементов матрицы:\n");
    int num, count = 0;
    for (int i = 0; i < a_n; i++)
    {
        for (int j = 0; j < a_m; j++)
        {
            int rc = -1;
            while (rc != OK)
            {
                fpurge(stdin);
                printf("\nВведите %d строку %d столбец.\n", i + 1, j + 1);
                if (scanf("%d", &num) == 1)
                {
                    a->data[i][j] = num;
                    if (num != 0)
                        count++;
                    rc = OK;
                }
                else
                    printf("Число введено неверно.\n");
            }
        }
    }
    
    b->k = count;

    if (alloc_special_matrix(b, count) != OK)
        return -4;


    make_special_matrix(a, b); 
    return OK;
}

int **allocated_matrix(const int n, const int m)
{
    int **data = malloc(n * sizeof(int*) + n * m * sizeof(int));

    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (int*)((char *) data + n * sizeof(int*) + i * m * sizeof(int));

    return data;
}

void make_special_matrix(usuale_matrix_t *a, special_matrix_t *b)
{
    int n = a->n;
    int m = a->m;
    int count = 0;
    int num; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            num = a->data[i][j];
            if (num != 0)
            {
                b->a[count] = num;
                b->ja[count] = i;
                b->ia[count] = j;
                count++;
            }
        }
    }
}

int create_special_matrix(usuale_matrix_t *a, special_matrix_t *b)
{
    int b_m, b_n, b_k;

    printf("\nВведите количество строк матрицы: \n");

    if (scanf("%d", &b_n) != 1 || b_n < 1 || b_n > 1000)
    {
        printf("\nДанные введены неверно.\n");
        return -3;
    }

    printf("\nВведите количество столбцов матрицы: \n");

    if (scanf("%d", &b_m) != 1 || b_m < 1 || b_m > 1000)
    {
        printf("\nДанные введены неверно.\n");
        return -3;
    }

    printf("\nВведите количество ненулевых элементов: \n");

    if (scanf("%d", &b_k) != 1 || b_k < 0 || b_k > b_n * b_m)
    {
        printf("\nДанные введены неверно.\n");
        return -3;
    }  

    b->n = b_n;
    a->n = b_n;

    a->m = b_m;
    b->m = b_m;

    b->k = b_k;

    if (alloc_special_matrix(b, b_k) != OK)
        return -4;

    a->data = allocated_matrix(b_n, b_m);
    if (a->data == NULL)
        return -4;

    int n, m, el, count = 0;
    for (int i = 0; i < b_k; i++)
    {
        int rc = -1;
        while (rc != OK)
        {
            fpurge(stdin);
            printf("\nВведите %d элемент(строка столбец элемент).\n", i + 1);

            if (scanf("%d %d %d", &n, &m, &el) == 3)
            {
                if (n > 0 && m > 0 && n <= b_n && m <= b_m)
                {
                    if (check_position(b->ja, b->ia, count, n - 1, m - 1) == OK)
                    {
                        b->a[count] = el;
                        b->ja[count] = n - 1;
                        b->ia[count] = m - 1;
                        count++;

                        a->data[n - 1][m - 1] = el;
                        rc = OK;
                    }
                    else
                        printf("\nДанные уже были введены.\n");
                }
                else    
                    printf("\nНомер строки или столбца введен неверно(Строка: 1 - %d. Столбец: 1 - %d).\n", b_n, b_m);
            }
            else
                printf("Число введено неверно.\n");
        }
    }

    return OK;
}

int check_position(int *a, int *b, int count, int n, int m)
{
    for (int i = 0; i < count; i++)
    {
        if (a[i] == n && b[i] == m)
            return -5;
    }
    return OK;
}


int auto_create_matrix(usuale_matrix_t *a, special_matrix_t *b)
{
    int b_m, b_n;

    printf("\nВведите количество строк матрицы: \n");

    if (scanf("%d", &b_n) != 1 || b_n < 1 || b_n > 1000)
    {
        printf("\nДанные введены неверно.\n");
        return -3;
    }

    printf("\nВведите количество столбцов матрицы: \n");

    if (scanf("%d", &b_m) != 1 || b_m < 1 || b_m > 1000)
    {
        printf("\nДанные введены неверно.\n");
        return -3;
    }

    b->n = b_n;
    a->n = b_n;

    a->m = b_m;
    b->m = b_m;

    b->k = b_m * b_n;

    a->data = allocated_matrix(b_n, b_m);

    if (alloc_special_matrix(b, b_n * b_m) != OK)
        return -4;

    int el, count = 0;
    for (int i = 0; i < b_n; i++)
    {
        for (int j = 0; j < b_m; j++)
        {
            el = rand() % 100;
            a->data[i][j] = el;
            b->ja[count] = i;
            b->ia[count] = j;
            b->a[count] = el;
            count++;
        }
    }
    return OK;
}

int alloc_special_matrix(special_matrix_t *b, int b_k)
{
    b->a = malloc(b_k * sizeof(int));
    if (b->a == NULL)
        return -4;

    b->ja = malloc(b_k * sizeof(int));
    if (b->ja == NULL)
        return -4;

    b->ia = malloc(b_k * sizeof(int));
    if (b->ia == NULL)
        return -4;
    
    return OK;
}
