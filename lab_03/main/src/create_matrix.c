#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "create_matrix.h"
#include "main.h"
#include "create_vector.h"

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

    if (alloc_special_matrix(b, count, a_n) != OK)
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
    int count_j = 0, count_i = 0;
    int num; 

    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = 0; j < m; j++)
        {
            num = a->data[i][j];
            if (num != 0)
            {
                b->a[count_j] = num;
                b->ja[count_j] = j;
                if (flag == 1)
                {
                    flag = 0;
                    b->ia[count_i] = count_j;
                    count_i++;
                }
                count_j++;
            }
        }

        if (flag == 1)
            b->ia[count_i++] = count_j;

    }

    b->ia[count_i] = count_j;
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

    if (alloc_special_matrix(b, b_k, b_n) != OK)
        return -4;

    a->data = allocated_matrix(b_n, b_m);
    if (a->data == NULL)
        return -4;

    int n, m, el;
    initialization_zero_matrix(a->data, b_n, b_m);
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
                    if (a->data[n - 1][m - 1] == 0)
                    {
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

    make_special_matrix(a, b);

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

    if (alloc_special_matrix(b, b_n * b_m, b_n) != OK)
        return -4;

    int el;
    for (int i = 0; i < b_n; i++)
    {
        for (int j = 0; j < b_m; j++)
        {
            el = rand() % 100;
            a->data[i][j] = el;
        }
    }

    make_special_matrix(a, b);
    return OK;
}

int alloc_special_matrix(special_matrix_t *b, int b_k, int b_n)
{
    b->a = malloc(b_k * sizeof(int));
    if (b->a == NULL)
        return -4;

    b->ja = malloc(b_k * sizeof(int));
    if (b->ja == NULL)
        return -4;

    b->ia = malloc((b_n + 1) * sizeof(int));
    if (b->ia == NULL)
        return -4;
    
    return OK;
}
