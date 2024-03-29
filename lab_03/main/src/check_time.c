#include <stdio.h>
#include <time.h>
#include <math.h>
#include "stdlib.h"
#include "check_time.h"
#include "create_matrix.h"
#include "create_vector.h"
#include "main.h"
#include "matrix_free.h"
#include "output_information.h"
#include "multiplication_matrix.h"
#include "errors.h"

int check_time()
{
    int lenl = 100;

    usuale_matrix_t a;
    special_matrix_t b;
    vector_matrix_t vector;
    usuale_matrix_t vector_a;

    usuale_matrix_t result_a;
    special_matrix_t result_b; 
    
    while (lenl < 1100)
    {
        printf("\nРазмерность: %d\n", lenl);

        test_auto_create_matrix(&a, &b, &result_a, &result_b, lenl);
        test_auto_create_vector(&vector, &vector_a, lenl);

        // output_matrix_vector(&a, &b, &vector);
        
        clock_t start, end;
        double usuale_mull, special_mull;

        start = clock(); //замерка обычной матриццы
        check_multiplication_usuale_matrix(&a, &vector_a, &result_a);
        end = clock();
        usuale_mull = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Время умножения простой матрицы: %fc\n", usuale_mull);
        printf("Память затраченная на простую матрицу: %lu\n", (&a)->n * (&a)->m * sizeof(int));
        printf("Память затраченная на простую матрицу-столбец: %lu\n", (&vector_a)->n * (&vector_a)->m * sizeof(int));

        printf("\n");
        start = clock(); //замерка специальной матрицы
        check_multiplication_special_matrix(&b, &vector, &result_b);
        end = clock();
        special_mull = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Время умножения разреженной матрицы: %fc\n", special_mull);
        printf("Память затраченная на разреженную матрицу: %lu\n", 2 * (&b)->k * sizeof(int) + (&b)->n * sizeof(int));
        printf("Память затраченная на разреженную матрицу-столбец: %lu\n", (&vector)->k * sizeof(int) + (&vector)->n * sizeof(int));

        free((&a)->data);
        free((&vector_a)->data);
        free((&result_a)->data);

        free_special_matrix(&b);
        free_vector(&vector);
        free_special_matrix(&result_b);

        printf("\n=============================================================\n");

        lenl += 100;

    }

    return OK;
}

void check_multiplication_special_matrix(special_matrix_t *b, vector_matrix_t *c, special_matrix_t *result_b)
{
    int b_n = b->n;

    // printf("%d %d", );
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
}

void check_multiplication_usuale_matrix(usuale_matrix_t *a, usuale_matrix_t *c, usuale_matrix_t *result_a)
{
    for (int i = 0; i < a->n; i++)
    {
        for (int j = 0; j < c->m; j++)
        {
            for (int k = 0; k < a->m; k++)
                result_a->data[i][j] += a->data[i][k] * c->data[k][j];
        }
    }
}


void test_auto_create_matrix(usuale_matrix_t *a, special_matrix_t *b, usuale_matrix_t *res_a, special_matrix_t *res_b, int lenl)
{
    a->n = lenl;
    a->m = lenl;
    b->m = lenl;
    b->n = lenl;

    int b_k = lenl * lenl / 1000 * 90, k = 0;

    b->k = b_k;
    alloc_special_matrix(b, b_k, lenl);
    a->data = allocated_matrix(a->n, a->m);
    initialization_zero_matrix(a->data, lenl, lenl);

    res_a->data = allocated_matrix(lenl, 1);
    res_a->n = lenl;
    res_a->m = 1;
    res_b->k = lenl;
    int index = 0;
    for (int i = 0; i < lenl; i++)
    {
        int flag = 1;
        for (int j = 0; j < lenl; j++)
        {
            if (k < b_k)
            {
                if (flag == 1)
                {
                    flag = 0;
                    b->ia[index] = k;
                    index++;
                }
                // int el = rand() % 100;
                int el = k + 1;
                if (el != 0)
                {
                    b->a[k] = el;
                    b->ja[k] = j;
                }
                a->data[i][j] = el;
                k++;
            }
            else
                a->data[i][j] = 0;
        }
        if (flag == 1)
            b->ia[index++] = k;
    }
    b->ia[index] = k;

    alloc_special_matrix(res_b, k, lenl);

    res_b->n = lenl;
    res_b->m = 1;
}

void test_auto_create_vector(vector_matrix_t *c, usuale_matrix_t *vctr, int lenl)
{
    int a_k = lenl / 100 * 90;

    c->a = malloc(a_k * sizeof(int));
    c->ja = malloc((lenl + 1) * sizeof(int));
    c->n = lenl + 1;
    c->k = a_k;
    vctr->m = 1;
    vctr->n = lenl;
    vctr->data = allocated_matrix(lenl, 1);
    initialization_zero_matrix(vctr->data, lenl, 1);

    for (int i = 0; i < a_k; i++)
    {
        int el = rand() % 100;
        vctr->data[i][0] = el;
    }

    make_special_vector(c, vctr);
}
