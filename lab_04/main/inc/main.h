#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX_LEN_STACK_ARRAY 1000
#define MAX_AREAS_NUM 50

//Стек в виде массива
typedef struct array_stack
{
    char *symbol;
    int size;
} array_stack_t;

//Стек в виде связанного списка
typedef struct list_stack 
{
    char symbol;
    struct list_stack *next;
} list_stack_t;

//Массив с памятью удаленных элементов
typedef struct free_areas
{
    list_stack_t *arr[MAX_AREAS_NUM];
    int len;
} free_areas_t;

//Стек в виде массива
typedef struct num_stack
{
    int num[MAX_LEN_STACK_ARRAY];
    int size;
} num_stack_t;

typedef struct num_stack_list
{
    int symbol;
    struct num_stack_list *next;
} num_stack_list_t;

#endif
