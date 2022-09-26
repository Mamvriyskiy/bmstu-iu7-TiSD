#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"
#include "main.h"
#include "error.h"

//Рапсредление числа по структурам
int accumulation_struct_number(number_t *struct_number, char *number, int *mantissa_i, int *order_i) 
{
    int exp = 0;
    int flag = 0;
    int last_flag = 0;
    int flag_i = 0;
    int flag_zero = 0;
    int i = 0;
    while (*number)
    {
        if (i == 0 && *number == '-') //Запись в структуру + или -, стоящих до числа
            struct_number->first_sign_number = -1;
        else if (i == 0 && *number == '+')
            struct_number->first_sign_number = 1;
        // else if (i == 0)
        //     struct_number->first_sign_number = 0;

        if (last_flag == 1) //Запись в структуру + или -, стоящих после экспоненты
        {
            if (*number == '-')
                struct_number->second_sign_number = -1;
            else 
                struct_number->second_sign_number = 1;
            flag = 1;
            last_flag = 0;
        }

        if (*number == '.') //Запись в струкутру позиции точки
        {
            struct_number->power_position = i;
            flag_i = 1;
        }
        else if (*number == 'e') //Запись в структуру позиции экспоненты
        {
            last_flag = 1;
            flag = 1;
            struct_number->exp_position = i;
        }
        else if (flag == 0 && *number != '\n' && *number != '-' && *number != '+') //Запись в структуру мантиссы
        {
            if ((*number - '0') != 0)
                flag_zero = 1;

            if (flag_zero == 1)
            {
                struct_number->mantissa[*mantissa_i] = (*number - '0');
                *mantissa_i += 1;
            }
            else
                exp--;
    
            if (flag_i == 0)
                i++;
        }
        else if (flag == 1 && *number != '\n' && *number != '-' && *number != '+') //Запись в структуру порядка
        {
            struct_number->order[*order_i] = (*number - '0');
            *order_i += 1; 
        }
        number++;
    }
    return exp;
}

void output_result(number_t *result_number, int lenl_mantissa)
{
    printf("Result: ");
    if (result_number->first_sign_number == - 1)
        printf("-");
    else 
        printf("+");
    
    if (result_number->mantissa[0] == 0)
    {
        printf("0.");
        print(result_number->mantissa, 1, lenl_mantissa);
    }
    else
    {
        printf("0.");
        print(result_number->mantissa, 0, lenl_mantissa);
    }
        
    printf("e");

    int a = result_number->order[0];
    printf("%d", a);
}

void print(int *array, int i, int lenl)
{
    for (; i < lenl; i ++)
    {
        printf("%d", array[i]);
    }
}

int creat_number(int *a, int size)
{
    int number = 0;
    for (int i = 0; i < size; i++)
    {
        number = number * 10 + a[i];
    }
    return number;
}

int without_zero(int *array)
{
    int a = 0;
    for (int i = 30 - 1; i >= 0; i--)
    {
        if (array[i] != 0)
        {
            break;
        }
        a++;
    }
    return a;
}
