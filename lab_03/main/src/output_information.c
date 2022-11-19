#include <stdio.h>
#include <errors.h>
#include <output_information.h>
#include "main.h"

void programm_menu()
{
    printf("\n--------------Меню--------------\n"
           "1 - Ввести матрицу\n"
           "2 - Ввести вектор-стоблец\n"
           "3 - Умножить матрицу на вектор\n"
           "4 - Вывести матрицы и вектор\n"
           "5 - Замерить эффективность\n"
           "0 - Выход\n");
}

void print_inform_about_matrix()
{
    printf("\n"
           "1 - Ввести матрицу в обычном ввиде\n"
           "2 - Ввести матрицу в разреженном ввиде\n"
           "3 - Автозаполение матрицы\n"
           "0 - Вернуться в главное меню\n");
}

void print_inform_about_vector()
{
    printf("\n"
           "1 - Ввести столбец-вектор\n"
           "2 - Автозаполение столбца-вектора\n"
           "0 - Вернуться в главное меню\n");
}

void print_information_multiplication()
{
    printf("\n"
           "1 - Умножение простой матрицы на вектор-столбец\n"
           "2 - Умножение разреженной матрицы на вектор-столбец\n"
           "0 - Выход в главное меню\n");
}

void output_matrix_vector(usuale_matrix_t *a, special_matrix_t *b, vector_matrix_t *c)
{
    int n = a->n;
    int m = a->m;

    if (n <= 0 || m <= 0)
        printf("\nМатрица не была введена.\n");
    else
    {
        //print usual_matrix
        if (n > 50 || m > 50)
            printf("\nРазмер матрицы слишком большой. Выведена не будет.\n");
        else 
        {
            printf("\nВывод обычной матрицы: \n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    printf("%d ", a->data[i][j]);
                printf("\n");
            }
        }

        if (b->k > 50)  
            printf("\nРазмер разреженной матрицы слишком большой. Выведена не будет.\n");
        else
        {
            printf("\nВывод разреженной матрицы: \n\n");
            int count = b->k;
            printf("Элемент:        ");
            for (int i = 0; i < count; i++)
                printf("%d ", b->a[i]);
            printf("\n");

            printf("Индекс столбца:  ");
            for (int i = 0; i < count; i++)
                printf("%d ", b->ja[i]);
            printf("\n");

            printf("Индекс строки: ");
            for (int i = 0; i < n + 1; i++)
                printf("%d ", b->ia[i]);
            printf("\n");
        }
    }

    if (c->n <= 0 || c->n > 1000)
        printf("\nСтолбец-вектор не был введен.\n");
    else 
    {
        if (c->k > 50)
        {
           printf("\nРазмер вектора-столбца слишком большой. Выведена не будет.\n"); 
        }
        else
        {
            printf("\nВывод вектора-столбца: \n\n");
            int v = c->k;
            printf("Элемент:        ");
            for (int i = 0; i < v; i++)
                printf("%d ", c->a[i]);
            printf("\n");

            printf("Индекс строки:  ");
            for (int i = 0; i < c->n; i++)
                printf("%d ", c->ja[i]);
            printf("\n");
        }
    }
}
