#include <stdio.h>
#include "main.h"
#include "errors.h"
#include "output_information.h"
#include "input_matrix.h"
#include "create_matrix.h"
#include "create_vector.h"
#include "multiplication_matrix.h"

int main()
{
    int error = OK;
    int num = -1;

    usuale_matrix_t a;
    special_matrix_t b;
    vector_matrix_t vector;

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
                error = END_WORK_PROGRAMM;
                printf("\nПрограмма завершила работу.\n");
                break;
            case 1:
                input_matrix(&a, &b);
                break;
            case 2:
                input_vector(&vector);
                break;
            case 3:
                multiplication_matrix(&a, &b, &vector, &result_a, &result_b);
                break;
            case 4:
                output_matrix_vector(&a, &b, &vector);
                break;
            case 5:
                //замерить эффективность
                break;

        }

    }
    return OK;
}


