#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "errors.h"
#include "push_pop.h"
#include "print_stack.h"
#include "stack_allocated.h"
#include "time_test.h"

#define LENL 1000

void time_test()
{

    int i = 100;
    while (i < 1100)
    {
        array_stack_t stack_array;
        (&stack_array)->size = 0;
        (&stack_array)->symbol = NULL;

        list_stack_t *stack_list = NULL;
        stack_list = NULL;

        stack_array.symbol = allocated_array(LENL);

        // time_machine(&stack_array, &stack_list, i);
        clock_t start, end;

        start = clock();
        for (int j = 0; j < i; j++)
        {
            push_array_stack(&stack_array, rand() % 100);
        }
        end = clock();
        // printf("Time array_add: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);  
        double add_array = (double)(end - start) / CLOCKS_PER_SEC;
        

        start = clock();
        for (int j = 0; j < i; j++)
        {
            push_list_stack(&stack_list, rand() % 100);
        }
        end = clock();
        // printf("Time list_add: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); 
        double add_list = (double)(end - start) / CLOCKS_PER_SEC;


        start = clock();
        for (int j = 0; j < i; j++)
        {
            char el;
            pop_array_stack(&stack_array, &el);
        }
        end = clock();
        // printf("Time array_delete: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); 
        double delete_array = (double)(end - start) / CLOCKS_PER_SEC;


        start = clock();
        for (int j = 0; j < i; j++)
        {
            pop_list_stack(&stack_list);
        }
        end = clock();
        // printf("Time list_delete: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); 
        double delete_list = (double)(end - start) / CLOCKS_PER_SEC;

        printf("--------------------------------------------------------------\n");
        printf("|              |  Стек Массив         |  Стек Лист           |\n");
        printf("--------------------------------------------------------------\n");
        printf("| Рамерность   | %-20d | %-20d |\n", i, i);
        printf("--------------------------------------------------------------\n");
        printf("| Добавление   | %-18lf с | %-18lf с |\n", add_array, add_list);
        printf("--------------------------------------------------------------\n");
        printf("| Удаление     | %-18lf с | %-18lf с |\n", delete_array, delete_list);
        printf("--------------------------------------------------------------\n");
        printf("| Память       | %-15lu байт | %-15lu байт |\n", i * sizeof(char) + sizeof(int), i * sizeof(list_stack_t));
        printf("--------------------------------------------------------------\n");
    
        printf("Процентное соотношение добавление: %lf %%\n", add_list / add_array * 100);
        printf("Процентное соотношение удаления:   %lf %%\n", delete_list / delete_array * 100);

        printf("\n\n");
        


        i += 100;
    }
}

