#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "errors.h"
#include "output_information.h"
#include "input_matrix.h"
#include "create_matrix.h"
#include "create_vector.h"
#include "multiplication_matrix.h"
#include "check_time.h"
#include "matrix_free.h"

int main()
{
    int error = OK;
    int num = -1;

    usuale_matrix_t a;
    special_matrix_t b;
    vector_matrix_t vector;
    usuale_matrix_t vector_a;

    usuale_matrix_t result_a;
    special_matrix_t result_b;  

    while (error == OK)
    {
        programm_menu();

        printf("\nВведите комманду: ");
        fpurge(stdin);
         
        if (scanf("%d", &num) != 1)
        {
            printf("\nДанные введены неверно.\n");
            continue;
        }

        switch(num)
        {
            case 0:
                free((&a)->data);
                free_special_matrix(&b);
                free_vector(&vector);

                free((&result_a)->data);
                free_special_matrix(&result_b);
                error = END_WORK_PROGRAMM;
                printf("\nПрограмма завершила работу.\n");
                break;
            case 1:
                input_matrix(&a, &b);
                break;
            case 2:
                input_vector(&vector, &vector_a);
                break;
            case 3:
                multiplication_matrix(&a, &b, &vector, &result_a, &result_b, &vector_a);
                break;
            case 4:
                output_matrix_vector(&a, &b, &vector);
                break;
            case 5:
                check_time();
                break;

        }

    }
    return OK;
}


