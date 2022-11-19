#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "errors.h"
#include "print_menu.h"
#include "create_stack.h"
#include "print_stack.h"
#include "add_delete.h"
#include "expresion.h"
#include "time_test.h"

int main()
{
    int error = OK;
    int num = -1;

    array_stack_t stack_array;
    (&stack_array)->size = 0;
    (&stack_array)->symbol = NULL;

    size_t size_list = 0;
    list_stack_t *stack_list = NULL;
    stack_list = NULL;

    free_areas_t free_areas;
    free_areas.len = 0;

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
                printf("\nПрограмма завершила работу!\n");
                free((&stack_array)->symbol);
                return OK;
            case 1:
                create_array_stack(&stack_array);
                break;
            case 2:
                add_new_element_array_stack(&stack_array);
                break;
            case 3:
                delete_element_array_stack(&stack_array);
                break;
            case 4:
                print_array_stack(&stack_array);
                break;
            case 5:
                if (stack_list != NULL)
                    printf("\nCтэк уже создан. Чтобы добавить, удалить или проверить на полидромность пользуйтесь меню.\n");
                else
                    create_list_array(&stack_list, &size_list);
                break;
            case 6:
                add_new_element_list(&stack_list, &size_list);
                break;
            case 7:
                delete_list_array(&stack_list, &size_list, &free_areas);
                break;
            case 8:
                print_list_array(stack_list);
                break;
            case 9:
                print_free_areas(&free_areas);
                break;
            case 10:
                solve_arithmetic_expression();
                break;
            case 11:
                time_test();
                break;
        }
    }
    return error;
}

