#include <stdio.h>
#include "errors.h"
#include "output_information.h"
#include "input_matrix.h"
#include "main.h"
#include "create_matrix.h"

void input_matrix(usuale_matrix_t *a, special_matrix_t *b)
{
    int rc = OK;
    int num = -1;
    while (rc == OK)
    {
        print_inform_about_matrix();
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
                create_usuale_matrix(a, b);
                break;
            case 2:
                create_special_matrix(a, b);
                break;
            case 3:
                auto_create_matrix(a, b);
                break;
            case 0:
                rc = END_WORK_PROGRAMM;
                break;
        }
    }
}

